// generate 3 frequencies on an Si5351
// bobnet 20170119

#include <Wire.h>
#include <Adafruit_SI5351.h>

Adafruit_SI5351 clockgen = Adafruit_SI5351();

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Si5351 40 / 80 / 120 KHz Clockgen Test"); Serial.println("");
  if (clockgen.begin() != ERROR_NONE)
  {
    Serial.print("Ooops, no Si5351 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  Serial.println("OK!");
  // 40 KHz
  clockgen.setupPLLInt(SI5351_PLL_A, 32);
  clockgen.setupMultisynth(0, SI5351_PLL_A, 625, 0, 1);
  clockgen.setupRdiv(0, SI5351_R_DIV_32);
  // 80 KHz
  clockgen.setupPLLInt(SI5351_PLL_A, 32);
  clockgen.setupMultisynth(1, SI5351_PLL_A, 625, 0, 1);
  clockgen.setupRdiv(1, SI5351_R_DIV_16);
  // 120 KHz
  clockgen.setupPLLInt(SI5351_PLL_B, 24);
  clockgen.setupMultisynth(2, SI5351_PLL_B, 625, 0, 1);
  clockgen.setupRdiv(2, SI5351_R_DIV_8);
  clockgen.enableOutputs(true);
}

void loop(void) 
{  
}
