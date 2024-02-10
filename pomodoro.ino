#include <UTFT.h>

extern uint8_t BigFont[];

UTFT myGLCD(ILI9486,38,39,40,41);

int long countdownDuration = 45 * 60 * 1000;

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  randomSeed(analogRead(0));
  
  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);

  // Clear the screen and draw the frame
  myGLCD.clrScr();
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("HELLO, EZEKIEL", CENTER, 100, 0);
  myGLCD.print("WORK HARDER", CENTER, 130, 0);


}

void loop() {

  countdownDuration = countdownDuration - 1;
  
  String timer = String(countdownDuration);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print(timer, CENTER, 175, 0);
  delay(1000);
  

}

