![Alt text](avatar.png "Optional title")
# 🔥 FireNote

![npm bundle size (version)](https://img.shields.io/badge/version-0.0.1-darkblue)  ![npm bundle size (version)](https://img.shields.io/badge/language-c++-red)  ![npm bundle size (version)](https://img.shields.io/badge/framework-arduino-lightblue) 

Ein automatischer Feuermelder mit dem ESP32, der Rauch & Gaskonzentration misst und optische & akustische Alarme auslöst.


## ✨ Features
- 🔥 Analoger Flammensensor (Infrarot)
- 📊 Gasppm-Berechnung in Echtzeit
- 🔴 Visueller Alarm (integrierte LED)
- 🔊 Akustischer Alarm (Piezo-Buzzer)
- 📈 Serielles Monitoring der Sensorwerte
- 🔧 Einfache Kalibrierung des Schwellenwerts

## 📋 Hardware Komponenten
| Komponente         | Spezifikation               |
|--------------------|-----------------------------|
| Microcontroller    | ESP32 Dev Board             |
| Flammensensor      | IR Flame Sensor (Analog)    |
| LED                | Integrierte LED (GPIO2)     |
| Buzzer             | Piezo-Summer (5V)           |
| Widerstände         | Je nach Sensor erforderlich |

## 🚨 Funktionsweise
Der Code implementiert folgende Logik:
1. Liest analogen Sensorwert (0-4095)
2. Umrechnung in ppm-Werte
3. Vergleicht mit einstellbarem Schwellenwert
4. Aktiviert Alarm bei Überschreitung:
   - Rote LED leuchtet
   - Buzzer ertönt (1000Hz)
5. Serielle Ausgabe der Messwerte

## 🔧 Kalibrierung
1. Messung in normaler Umgebung durchführen
2. Durchschnittswerte im seriellen Monitor notieren
3. Schwellenwert in Zeile 7 anpassen:
```cpp
float gasThreshold = 2; // Höheren Wert für weniger empfindlichen Alarm

