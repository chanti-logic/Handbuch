#include <U8x8lib.h>

#define STEP_PIN 2
#define DIR_PIN 3
#define START_BUTTON_PIN 4
#define STOP_BUTTON_PIN 5
#define END_LEFT_PIN 11
#define END_RIGHT_PIN 7
#define MAIN_SWITCH_PIN 8
#define SPEED_SENSOR_PIN 9
#define ENCODER_CLK A1
#define ENCODER_DT A2
#define ENCODER_SW A3

bool motorRunning = false;
bool richtungLinks = false;
bool systemAktiv = false;
bool letzteSchalterstellung = true;
bool endLeftPressed = false;
bool endRightPressed = false;
bool geschwindigkeitGeWaehlt = false;
bool messungBeendet = false;
bool messungAktiv = false;
bool fahrtGestartet = false;

volatile unsigned long pulseCount = 0;
unsigned long startzeit = 0;
unsigned long endzeit = 0;
const float WEG_CM = 36.0;

int geschwindigkeitsStufe = 1;
int delayWert[] = {1500, 1000, 900, 800, 600};

U8X8_SSD1309_128X64_NONAME2_HW_I2C u8x8(10, A4, A5);

void countPulse() {
  if (messungAktiv) {
    pulseCount++;
  }
}

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(START_BUTTON_PIN, INPUT_PULLUP);
  pinMode(STOP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(END_LEFT_PIN, INPUT_PULLUP);
  pinMode(END_RIGHT_PIN, INPUT_PULLUP);
  pinMode(MAIN_SWITCH_PIN, INPUT_PULLUP);
  pinMode(SPEED_SENSOR_PIN, INPUT_PULLUP);
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), countPulse, FALLING);

  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clear();
  u8x8.drawString(0, 0, "Starte...");
}

void loop() {
  bool schalterZustand = digitalRead(MAIN_SWITCH_PIN) == LOW;

  if (schalterZustand != letzteSchalterstellung) {
    letzteSchalterstellung = schalterZustand;
    if (schalterZustand) {
      systemAktiv = true;
      motorRunning = false;
      geschwindigkeitGeWaehlt = false;
      u8x8.clear();
      u8x8.drawString(0, 1, "SYSTEM AKTIV");
      u8x8.drawString(0, 3, "Willkommen!");
      u8x8.drawString(0, 5, "Stufe waehlen");
    } else {
      systemAktiv = false;
      motorRunning = false;
      messungAktiv = false;
      u8x8.clear();
      u8x8.drawString(0, 1, "SYSTEM AUS");
      u8x8.drawString(0, 3, "Auf Wiedersehen!");
    }
    delay(100);
  }

  if (!systemAktiv) return;

  // Geschwindigkeit wählen
  if (!geschwindigkeitGeWaehlt) {
    static int lastClk = digitalRead(ENCODER_CLK);
    int clk = digitalRead(ENCODER_CLK);
    int dt = digitalRead(ENCODER_DT);

    if (clk != lastClk && clk == LOW) {
      if (dt == HIGH && geschwindigkeitsStufe < 5) geschwindigkeitsStufe++;
      if (dt == LOW && geschwindigkeitsStufe > 1) geschwindigkeitsStufe--;
      u8x8.clear();
      u8x8.drawString(0, 0, "Stufe waehlen:");
      char buf[16];
      snprintf(buf, sizeof(buf), "Stufe %d", geschwindigkeitsStufe);
      u8x8.drawString(0, 1, buf);
      delay(150);
    }
    lastClk = clk;

    if (digitalRead(ENCODER_SW) == LOW) {
      u8x8.clear();
      u8x8.drawString(0, 0, "Stufe gewaehlt:");
      char buf[16];
      snprintf(buf, sizeof(buf), "Stufe %d", geschwindigkeitsStufe);
      u8x8.drawString(0, 1, buf);
      u8x8.drawString(0, 3, "START DRUECKEN");
      geschwindigkeitGeWaehlt = true;
      delay(500);
      while (digitalRead(ENCODER_SW) == LOW);
    }
    return;
  }

  // START gedrückt
  if (digitalRead(START_BUTTON_PIN) == LOW && !motorRunning) {
    // Nur bei neuem Start muss linker Endschalter aktiv sein
    if (!fahrtGestartet && digitalRead(END_LEFT_PIN) == HIGH) return;

    motorRunning = true;
    messungAktiv = true;

    if (!fahrtGestartet) {
      richtungLinks = false;
      setDirection();
      startzeit = millis();
      messungBeendet = false;
      fahrtGestartet = true;

      u8x8.clear();
      u8x8.drawString(0, 0, "FAHRT STARTET");
      u8x8.drawString(0, 1, "-> nach rechts");
    } else {
      setDirection();
      u8x8.clear();
      u8x8.drawString(0, 0, "FAHRT FORTGESETZT");
      u8x8.drawString(0, 1, richtungLinks ? "<= Rueckfahrt" : "-> Hinweg");
    }

    while (digitalRead(START_BUTTON_PIN) == LOW);
  }

  // STOP jederzeit möglich
  if (digitalRead(STOP_BUTTON_PIN) == LOW && motorRunning) {
    motorRunning = false;
    messungAktiv = false;
    u8x8.drawString(0, 5, "STOPP GEDRUECKT");
    while (digitalRead(STOP_BUTTON_PIN) == LOW);
  }

  // Rechts erreicht → Richtung umkehren
  bool rightNow = digitalRead(END_RIGHT_PIN) == LOW;
  if (rightNow && !endRightPressed && motorRunning && !richtungLinks) {
    richtungLinks = true;
    setDirection();
    u8x8.clear();
    u8x8.drawString(0, 0, "ENDE RECHTS");
    u8x8.drawString(0, 1, "<= Rueckfahrt");
    delay(300);
  }
  endRightPressed = rightNow;

  // Links erreicht → Fahrtende
  bool leftNow = digitalRead(END_LEFT_PIN) == LOW;
  if (leftNow && !endLeftPressed && motorRunning && richtungLinks) {
    motorRunning = false;
    messungAktiv = false;
    messungBeendet = true;
    fahrtGestartet = false;
    endzeit = millis();

    float sekunden = (endzeit - startzeit) / 1000.0;
    float geschwindigkeit = (WEG_CM * 2) / sekunden;

    u8x8.clear();
    u8x8.drawString(0, 1, "FAHRT BEENDET");
    char buf[16];
    u8x8.drawString(0, 3, "Geschwindigkeit:");
    snprintf(buf, sizeof(buf), "V: %.2f cm/s", geschwindigkeit);
    u8x8.drawString(0, 4, buf);
    u8x8.drawString(0, 6, "Stufe waehlen");

    geschwindigkeitGeWaehlt = false;
  }
  endLeftPressed = leftNow;

  // Motorbewegung
  if (motorRunning) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayWert[geschwindigkeitsStufe - 1]);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayWert[geschwindigkeitsStufe - 1]);
  }
}

void setDirection() {
  digitalWrite(DIR_PIN, richtungLinks ? LOW : HIGH);
}

