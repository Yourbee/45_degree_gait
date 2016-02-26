#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "servoClass.h"
#include "condition.h"

extern Adafruit_PWMServoDriver pwm;// = Adafruit_PWMServoDriver();

#define freq 60
#define timspace  800
MyServo ser[4][3];  //定义舵机对象
int i, j;
int buer[3] = {1, 5, 1};

void setup() {
  for (i = 0; i <= 3; i++)
  for (j = 0; j <= 2; j++) {
    ser[i][j].si = i;
    ser[i][j].sj = j;
    ser[i][j].num = 3 * i + j;
    }                             //初始化舵机参数
    // Serial.begin(9600);
    // Serial.println("test begin!");
    // Serial.println();
    pwm.begin();
    pwm.setPWMFreq(freq);

  ser[0][0].setServoPWM(110, 560); 
  ser[0][1].setServoPWM(110, 560);
  ser[0][2].setServoPWM(140, 565); //0-170
  ser[1][0].setServoPWM(120, 540);
  ser[1][1].setServoPWM(110, 560);
  ser[1][2].setServoPWM(110, 562);
  ser[2][0].setServoPWM(90, 520);
  ser[2][1].setServoPWM(90, 540);
  ser[2][2].setServoPWM(120, 560);
  ser[3][0].setServoPWM(110, 540);
  ser[3][1].setServoPWM(110, 540); //broken
  ser[3][2].setServoPWM(110, 540);
}

void loop() {
  while (1) {

    while (buer[0]) {
      init_1();   //初始化

      buer[0]--;
    }
    while (buer[1]) {

      //first step
      ser[1][1].changle(105);
      ser[3][1].changle(85);
      ser[3][2].changle(160);
      ser[0][1].changle(95);
      ser[0][2].changle(160);
      ser[2][1].changle(75);

      delay(timspace);

      ser[1][0].changle(95);
      delay(800);
      ser[1][1].changle(75);
      ser[3][1].changle(75);
      ser[3][2].changle(160);
      ser[0][1].changle(85);
      ser[2][1].changle(85);
      ser[2][2].changle(160);
      delay(800);

      ser[1][0].changle(115);
      delay(timspace);

      //second step
      ser[3][0].changle(95);
      delay(800);
      ser[3][1].changle(75);
      ser[1][1].changle(75);
      ser[1][2].changle(160);
      ser[0][1].changle(75);
      ser[0][2].changle(160);
      ser[2][1].changle(85);
      delay(800);

      ser[3][0].changle(115);
      delay(timspace);

      ser[0][0].changle(95);
      delay(800);
      ser[0][1].changle(95);
      ser[1][1].changle(105);
      ser[3][1].changle(85);
      ser[3][2].changle(160);
      ser[2][1].changle(75);
      ser[2][2].changle(160);
      delay(800);

      ser[0][0].changle(115);
      delay(timspace);

      ser[2][0].changle(95);
      delay(800);

      ser[2][1].changle(105);
      ser[1][1].changle(95);
      ser[1][2].changle(160);
      ser[3][1].changle(95);
      ser[0][1].changle(105);
      ser[0][2].changle(160);
      delay(800);
      ser[2][0].changle(115);
      delay(800);

      buer[1]--;
    }
  }
}



