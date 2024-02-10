#include <UTFT.h>

extern uint8_t BigFont[];

UTFT myGLCD(ILI9486,38,39,40,41);

int long countdownDuration = 45;

void setup() {
  randomSeed(analogRead(0));
  
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);

  myGLCD.clrScr();
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("HELLO, EZEKIEL", CENTER, 100, 0);
  myGLCD.print("WORK HARDER", CENTER, 130, 0);

}

void loop() {

  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);

  if (countdownDuration <= 0) {

    myGLCD.print("BREAK TIME!", CENTER, 175, 0);

  } else {

    countdownDuration = countdownDuration - 1;
    String timer = String(countdownDuration);
    myGLCD.print(timer, CENTER, 175, 0);

  }

  delay(1000 * 60);
  
}

