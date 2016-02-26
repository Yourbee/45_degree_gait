#include "servoClass.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

MyServo::MyServo() { //构造函数
  SERVOMIN = 90;
  SERVOMAX = 580;
  //中间值335
}
void MyServo::setServoPWM(int mi, int ma) { //修改pwm占空比
  SERVOMIN = mi;
  SERVOMAX = ma;
}

void MyServo::changle(int ang) {
  int i;

  if(angle<=ang)
    for(i=angle;i<=ang;i++){
      pwm.setPWM(num, 0, map(i, 0, 180, SERVOMIN, SERVOMAX));
      //delay(1);
    }
  if(angle>ang)
    for(i=angle;i>=ang;i--){
      pwm.setPWM(num, 0, map(i, 0, 180, SERVOMIN, SERVOMAX));
      //delay(1);
    }

  angle = ang;
  //printInfor();
}

void MyServo::addangle(int ang) {
  angle = ang;
  pwm.setPWM(num, 0, map(angle, 0, 180, SERVOMIN, SERVOMAX));
  //printInfor();
}

void MyServo::printInfor() { //打印数据函数
  Serial.print("servo:");
  Serial.print(si);
  Serial.print(" ");
  Serial.print(sj);
  Serial.print("  pinNum:");
  Serial.println(num);
  Serial.print("move to ");
  Serial.print(angle);
  Serial.println(" degree  ");
  Serial.print("PWM value:");
  Serial.println(map(angle, 0, 180, SERVOMIN, SERVOMAX));
  Serial.print("SERVOMIN:");
  Serial.print(SERVOMIN);
  Serial.print("  SERVOMAX:");
  Serial.println(SERVOMAX);
  Serial.println();
}
