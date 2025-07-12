<div>
  <p>
    <img width="35%" src="XXXX.jpg">
  </p>
  <b><h3> Automatisierungstechnik Projekt aus dem Jahr 2025 </h3></b>
  <p> Demonstrator für einen Schrittmotor mit <a href="https://www.arduino.cc"> Arduino-Ansteuerung </a></p>
</div>
<br>

# Betreuer: 
Prof. Dr. Elmar Wings

# Autoren (Name, Vorname, Matrikelnummer):
Crety, Chantal, XXXX
Mey, Hannah, 7024688
Perewersenko, Jessica, 7024880

# Projektbeschreibung: 
Im Rahmen dieses Projekts wurde ein vorhandener CNC-Tisch erweitert, um einen seiner Schrittmotoren als Demonstrator mit variabler Geschwindigkeitsregelung zubetreiben. 
Ziel war es, die technische Integration und Ansteuerung über einen Arduino Nano 33 BLE Sense umzusetzen und gleichzeitig eine benutzerfreundliche Bedienoberfläche zu schaffen.

# Aufgabenstellung:
Die Hauptaufgabe bestand darin, einen Schrittmotor des CNC-Tisches in mehreren Geschwindigkeitsstufen betreiben zu können. 
Die Steuerung sollte über einen Arduino Nano 33 BLE Sense erfolgen, wobei die Auswahl der Geschwindigkeit über Bedienelemente möglich sein sollte. 
Zusätzlich sollte ein optischer Geschwindigkeitssensor vom Typ LM393 die Drehzahl erfassen und zur Kontrolle auf einem Display ausgeben.

# Verzeichnisstruktur: 

## Autor und README
- [Author-Excel](author.xlsx)
  - Excel-Datei in der persönliche Daten über die einzelnen Gruppenmitglieder wiederzufinden sind
- [README](README.md)

## Anhang
- [Mindmap](LaTeXTemplate/Xmind/Schrittmotor_Mindmap.xmind)
- [Schaltplan](DemonstratorSchrittmotor/Appendix/SchaltplanFritzing) !!! NICHT FERTIG!!!

## Montageanleitung (sämtliche Inhalte und die verwendeten Bilder)
- [Montageanleitung](LaTeXTemplate/Montage)
- [Inhalte](LaTeXTemplate/Montage/Chapters)
  - Ort an dem sich die Tex-Dateien für die einzelnen Kapiteln der Montageanleitung befinden
- [Gestaltung](LaTeXTemplate/Montage/General)
  - In diesem Ordner sind Dateien, zur Gestaltung der Montageanleitung
- [Bilder](LaTeXTemplate/Montage/Images)
  - Ablage der Bilder, die in der Montageanleitung benutzt werden
- [PDF](LaTeXTemplate/Montage/MontageAnleitung.pdf)

## verwendeter Code !!! NICHT FERTIG!!!
- [Code](DemonstratorSchrittmotor/Code)
- [Arduino](DemonstratorSchrittmotor/Code/Arduino)
 - Testprogramm für den Arduino
- [DemonstratorSchrittmotor](DemonstratorSchrittmotor/Code/DemonstratorSchrittmotor)
 - Fertiges Programm für den Arduino
- [Encoder](DemonstratorSchrittmotor/Code/Encoder)
 - Testprogramm für den Encoder
- [html](DemonstratorSchrittmotor/Code/html)
 - Ordner für die doxygen Dokumentation
- [latex](DemonstratorSchrittmotor/Code/latex)
 - Ordner für die doxygen Dokumentation als Latex-Code
- [LED](DemonstratorSchrittmotor/Code/LED)
 - Testprogramm für die LED
- [OLEDDisplay](DemonstratorSchrittmotor/Code/OLEDDisplay)
 - Testprogramm für das OLED Display
- [Stepper](DemonstratorSchrittmotor/Code/Stepper)
 - Testprogramm für den Stepper
- [Taster](DemonstratorSchrittmotor/Code/Taster)
 - Testprogramm für den Taster
- [TastermitDebounce](DemonstratorSchrittmotor/Code/TastermitDebounce)
 - Testprogramm für den Taster mit Debounce

## Service- und Entwicklerdocumentation !!! NICHT FERTIG!!!
- [Service- und Entwicklerdocumentation](DemonstratorSchrittmotor/DeveloperDoc)
- [Inhalte](DemonstratorSchrittmotor/DeveloperDoc/Chapters)
  - Ort an dem sich die Tex-Dateien für die einzelnen Kapiteln der Service- und Entwicklerdocumentation befinden
- [Gestaltung](DemonstratorSchrittmotor/DeveloperDoc/General)
  - In diesem Ordner sind Dateien, zur Gestaltung der Service- und Entwicklerdocumentation
- [Bilder](DemonstratorSchrittmotor/DeveloperDoc/Images)
  - Ablage der Bilder, die in der Service- und Entwicklerdocumentation benutzt werden
- [Tikz](DemonstratorSchrittmotor/DeveloperDoc/tikz)
  - Tex-Dateien zur Ersetllung von Tikz-Diagrammen oder Zeichnungen
- [Service- und Entwicklerdocumentation-PDF](DemonstratorSchrittmotor/DeveloperDoc/DemonstratorSchrittmotor.pdf)

## Demontageanleitung (sämtliche Inhalte und die verwendeten Bilder)
- [Demontageanleitung](LaTeXTemplate/Demontageanleitung)
- [Inhalte](LaTeXTemplate/Demontageanleitung/Chapters)
  - Ort an dem sich die Tex-Dateien für die einzelnen Kapiteln der Demontageanleitung befinden
- [Gestaltung](LaTeXTemplate/Demontageanleitung/General)
  - In diesem Ordner sind Dateien, zur Gestaltung der Demontageanleitung
- [Bilder](DemonstratorSchrittmotor/Disassembly/Images) ----------------------------------------------------
  - Ablage der Bilder, die in der Demontageanleitung benutzt werden
- [PDF](LaTeXTemplate/Demontageanleitung/DemontageAnleitung.pdf)
  
## verwendete Quellen und bib-file (Datenblätter und Literatur in PDF) !!! NICHT FERTIG!!!
- [Dokumente](DemonstratorSchrittmotor/Documents)
- [Arduino IDE Dokumentation](DemonstratorSchrittmotor/Documents/ArduinoIDEDoku)
  - Quellen für die Softwaredokumentation von der Arduino Website
- [Datenblätter](DemonstratorSchrittmotor/Documents/Datenblätter)
  - Unter diesem Pfad befinden sich die Datenblätter, die für die Dokumentation benötigt wurden
- [Literatur](DemonstratorSchrittmotor/Documents/Literatur)
  - Hier befindet sich die verwendete Literatur
- [Bildquellen der Materialliste](DemonstratorSchrittmotor/Documents/MateriallisteQuellen)
- [Bibliothek](DemonstratorSchrittmotor/Documents/MyLiterature.bib)
  - Citavi Bibliothek mit allen genutzten Quelleinträgen

## Das Handbuch für den Demonstrator (sämtliche Inhalte und die verwendeten Bilder)
- [Handbuch](LaTeXTemplate/Manual)
- [Inhalte](LaTeXTemplate/Manual/Chapters)
  - Ort an dem sich die Tex-Dateien für die einzelnen Kapitel des Handbuches befinden
- [Gestaltung](LaTeXTemplate/Manual/General)
  - In diesem Ordner sind Dateien, zur Gestaltung des Handbuches
- [Bilder](LaTeXTemplate/Manual/Materialliste)
  - Ablage der Bilder, die im Handbuch benutzt werden
- [Handbuch-PDF](LaTeXTemplate/Manual/Handbuch.pdf)

## Das Poster zum Projekt (sämtliche Inhalte und die verwendeten Bilder)
- [Poster](LaTeXTemplate/Poster)
- [Bilder](LaTeXTemplate/Poster/images)
  - Ablage der Bilder, die im Poster benutzt werden
- [Poster-PDF](LaTeXTemplate/Poster/Schrittmotor_Poster.pdf)

## Literaturverzeichnis als Präsentation !!! NICHT FERTIG!!!
- [Bilder](DemonstratorSchrittmotor/Presentations/images)
  - Coverbilder der Quellen
- [Hintergrundbilder](DemonstratorSchrittmotor/Presentations/img)
- [Folien](DemonstratorSchrittmotor/Presentations/slides)
- [Literaturverzeichnis-PDF](DemonstratorSchrittmotor/Presentations/Literaturverzeichnis.pdf)

## Schnelleinstieg
- [Schnelleinstieg-PDF](LaTeXTemplate/Schnelleinstieg/Schnelleinstieg_Schrittmotor.pdf)