/* 
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /        __________   _________   ___________   __________    _________                             /
   /       /___   ___/  /   _____/  /  _____   /  /  _____   \  /  ______/       \\            //      /
   /          /  /     /  /        /  /    /  /  /  /    /  /  /  /_____        \\             //      /
   /         /  /     /  /        /  /____/  /  /  /___/  /   /  ______/   \\\   \\    []    //   ///  /
   /     ___/  /__   /  /_____   /   ____   /  /   ___   \   /  /_____        \\\\--]]]/\[[[--////     /
   /    /________/  /________/  /__/    /__/  /__/    \__/  /________/         /////--][][--\\\\\      /
   /                                                                         //   //--][][--\\   \\    /
   /   ______________________________________________________________           //    ][][    \\       /
   /                                                                                                   /
   /                                                                                                   /
   /  This program is free software for arduino; you can redistribute it and/or modify.                /
   /  Ce programme pour Arduino est libre et gratuit; vous pouvez le distribuez et/ou le modifier.     /
   /                                                                                                   /
   / Another codes / Autres codes:                                                                     /
   / https://www.icaremaker.com                                                                        /
   / Mail: ionocraft@hotmail.fr                                                                        /
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include "LedControl.h"

LedControl Ic=LedControl(7, 11, 10, 4);

unsigned long delayTime=250;

 int del=150;

 int ScoreR = 0;
 int ScoreB = 0;

 int switchStateRp = 0;
 int switchStateRn = 0;
 int switchStateBp = 0;
 int switchStateBn = 0;
 int switchStateR0 = 0;   

 int VerrouR = 0;
 int VerrouB = 0;

 int rouge = 1;
 int bleu = 1;

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void setup() {
  Ic.shutdown(0,false);
  Ic.shutdown(1,false);
  Ic.shutdown(2,false);
  Ic.shutdown(3,false);
  Ic.setIntensity(0,2);
  Ic.setIntensity(1,9);
  Ic.setIntensity(2,2);
  Ic.setIntensity(3,9);
  Ic.clearDisplay(0);
  Ic.clearDisplay(1);
  Ic.clearDisplay(2);
  Ic.clearDisplay(3);
 }


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

  void loop() {

  pinMode(6, OUTPUT);
 
  pinMode(2, INPUT);
  switchStateBn = digitalRead(2);
  pinMode(8, INPUT);
  switchStateR0 = digitalRead(8);
  pinMode(4, INPUT);
  switchStateBp = digitalRead(4);
  pinMode(12, INPUT);
  switchStateRn = digitalRead(12);
  pinMode(13, INPUT);
  switchStateRp = digitalRead(13);
 

  if (switchStateRp == HIGH){
    
    if (VerrouR == 0){
    
    ScoreR = (ScoreR + 1);
    VerrouR = (VerrouR + 1);
    delay(del);
    }
  }

  if (switchStateRp == LOW){
    VerrouR = 0;
  }

  if (switchStateRn == HIGH){
    
    if (VerrouR == 0){
    
    ScoreR = (ScoreR - 1);
    VerrouR = (VerrouR + 1);
    delay(del);
    }
  }

  if (switchStateRn == LOW){
    VerrouR = 0;
  }
  

  if (switchStateBp == HIGH){
    
    if (VerrouB == 0){
    
    ScoreB = (ScoreB + 1);
    VerrouB = (VerrouB + 1);
    delay(del);
    }
  }

  if (switchStateBp == LOW){
    VerrouB = 0;
  }

  if (switchStateBn == HIGH){
    
    if (VerrouB == 0){
    
    ScoreB = (ScoreB - 1);
    VerrouB = (VerrouB + 1);
    delay(del);
    }
  }

  if (switchStateBn == LOW){
    VerrouB = 0;
  }

  if (switchStateR0 == HIGH){
    ScoreB = 0;
    ScoreR = 0;
    }  
   
 
/////////////////////////////////////////
///////   AFFICHAGE DES EQUIPES   ///////
/////////////////////////////////////////
EquipeBleu(0);
EquipeRouge(2);
/////////////////////////////////////////

  if (ScoreR == 10){ScoreR = 0;}
  if (ScoreB == 10){ScoreB = 0;}
  if (ScoreR == -1){ScoreR = 0;}
  if (ScoreB == -1){ScoreB = 0;}

  if (ScoreR == 0){ZERO(1);}
  if (ScoreR == 1){UN(1);}
  if (ScoreR == 2){DEUX(1);}
  if (ScoreR == 3){TROIS(1);}
  if (ScoreR == 4){QUATRE(1);}
  if (ScoreR == 5){CINQ(1);}
  if (ScoreR == 6){SIX(1);} 
  if (ScoreR == 7){SEPT(1);}
  if (ScoreR == 8){HUIT(1);}
  if (ScoreR == 9){NEUF(1);
    delay(delayTime);
    digitalWrite(6, HIGH);
    delay(delayTime);
    digitalWrite(6, LOW);
  }

  if (ScoreB == 0){ZERO(3);}
  if (ScoreB == 1){UN(3);}
  if (ScoreB == 2){DEUX(3);}
  if (ScoreB == 3){TROIS(3);}
  if (ScoreB == 4){QUATRE(3);}
  if (ScoreB == 5){CINQ(3);}
  if (ScoreB == 6){SIX(3);} 
  if (ScoreB == 7){SEPT(3);}
  if (ScoreB == 8){HUIT(3);}
  if (ScoreB == 9){NEUF(3);
    delay(delayTime);
    digitalWrite(6, HIGH);
    delay(delayTime);
    digitalWrite(6, LOW);
  }

  
  }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
  
  void UN(int emplacement) {
	  byte imageUN[]=
{
  B00000000,
  B00000100,
  B10000100,
  B00000100, 
  B00000100,
  B10000100,
  B00000100,
  B00000000
}; 
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageUN[i]);}
  }

  void DEUX(int emplacement) {
	  
	 byte imageDEUX[]=
{
  B00000000,
  B00111110,
  B10000010,
  B00111110,
  B00100000,
  B10100000,
  B00111110,
  B00000000
}; 	  
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageDEUX[i]);}
  }

  void TROIS(int emplacement) {
	  byte imageTROIS[]=
{
  B00000000,
  B00111110,
  B10000010,
  B00111110,
  B00000010,
  B10000010,
  B00111110,
  B00000000
};  
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageTROIS[i]);}
  }

  void QUATRE(int emplacement) {
	  byte imageQUATRE[]=
{
  B00000000,
  B00100010,
  B10100010,
  B00111110,
  B00000010,
  B10000010,
  B00000010,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageQUATRE[i]);}
  }

  void CINQ(int emplacement) {
	  byte imageCINQ[]=
{
  B00000000,
  B00111110,
  B10100000,
  B00111110,
  B00000010,
  B10000010,
  B00111110,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageCINQ[i]);}
  }

  void SIX(int emplacement) {
	  byte imageSIX[]=
{
  B00000000,
  B00111110,
  B10100000,
  B00111110,
  B00100010,
  B10100010,
  B00111110,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageSIX[i]);}
  }

  void SEPT(int emplacement) {
	  byte imageSEPT[]=
{
  B00000000,
  B00111110,
  B10000010,
  B00000010,
  B00000010,
  B10000010,
  B00000010,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageSEPT[i]);}
  }

  void HUIT(int emplacement) {
	  byte imageHUIT[]=
{
  B00000000,
  B00111110,
  B10100010,
  B00111110,
  B00100010,
  B10100010,
  B00111110,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageHUIT[i]);}
  }

  void NEUF(int emplacement) {
	  byte imageNEUF[]=
{
  B00000000,
  B00111110,
  B10100010,
  B00111110,
  B00000010,
  B10000010,
  B00111110,
  B00000000
};
	  
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageNEUF[i]);}
  }

  void ZERO(int emplacement) {
	  byte imageZERO[]=
{
  B00000000,
  B00111110,
  B10100010,
  B00100010,
  B00100010,
  B10100010,
  B00111110,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageZERO[i]);}
  }


  void EquipeRouge(int emplacement) {
	  byte imageROUGE[]=
{
  B00000000,
  B01111100,
  B01000010,
  B01111100,
  B01100000,
  B01011000,
  B01000100,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageROUGE[i]);}
  }

  void EquipeBleu(int emplacement) {
	  byte imageBLEU[]=
{
  B00000000,
  B01111100,
  B01000010,
  B01111100,
  B01000010,
  B01000010,
  B01111100,
  B00000000
};
    for (int i = 0; i < 8; i++)
    {Ic.setRow(emplacement,i,imageBLEU[i]);}
  }
  
