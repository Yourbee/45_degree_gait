#include "condition.h"
#include "servoClass.h"
#include <arduino.h>

extern int i;
extern MyServo ser[4][3];

void init_1() //初始化
{
  for (i = 0; i <= 3; i++) {
    ser[i][0].addangle(115);
    delay(200);
  }

  for (i = 0; i <= 3; i++) {
    ser[i][1].addangle(90);
    delay(200);
  }

  for (i = 0; i <= 3; i++) {
    ser[i][2].addangle(160);
    delay(200);
  }
  delay(1500);
}
