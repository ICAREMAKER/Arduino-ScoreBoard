# Arduino-ScoreBoard
### 1-PREVIEW
![RobotCombat](https://github.com/ICAREMAKER/Arduino-ScoreBoard/assets/107696317/b2646e2e-f267-42b3-9fcb-4fe1898fc84d)

### 2-SCHEMA
![schema](https://github.com/ICAREMAKER/arduino-Score-generator/assets/107696317/d0eff3cf-0f77-42f9-a0b9-bc7e6856204c)

### 2-CODE
Vous devez installer la librairie: LedControl.h
```C
#include "LedControl.h"
LedControl lc=LedControl(13,12,11,1);  // Pins: DIN,CLK,CS, # of Display connected
```
![331127688-3c6cceb5-04ce-42fc-87c7-59c88b767277](https://github.com/ICAREMAKER/arduino-Score-generator/assets/107696317/c4b00203-6f6d-42ab-ac15-7237d3ce7e77)

```C
void setup() {
  //Setup du bouton poussoir
  score = 0;
  pinMode(buttonPin, INPUT_PULLUP);
  //Setup de l'afficheur 8x8
  lc.shutdown(0,false);  // Affichage de réveil
  lc.setIntensity(0,1);  // Niveau d'intensité lumineuse
  lc.clearDisplay(0);    // Affichage clair

   Serial.begin(9600);
}
```
```C
void loop() {
  
  // Lire l'etat du bouton poussoir
  buttonState = digitalRead(buttonPin);

  // Selon l'etat du bouton, j'active qqchose
    if ((buttonState == LOW) and (verrou == HIGH)){
    Result = ++score;
    verrou = LOW;
    } 
  
  if (buttonState == HIGH) 
  {verrou = HIGH;
  }
  
if (Result == 0) {ZERO();}
if (Result == 1) {UN();}
if (Result == 2) {DEUX();}
if (Result == 3) {TROIS();}
if (Result == 4) {QUATRE();}
if (Result == 5) {CINQ();}
if (Result == 6) {SIX();}
if (Result == 7) {SEPT();}
if (Result == 8) {HUIT();}
if (Result == 9) {NEUF(); score = -1;}
      
 
delay(100);
}
```

```C
void ZERO()
{
	byte image0[] =
{
   B00000000,  
   B01111110,
   B11111111,
   B10100001,
   B10010001,
   B11111111,
   B01111110,
   B00000000
};

  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,image0[i]);
  }
}
```
