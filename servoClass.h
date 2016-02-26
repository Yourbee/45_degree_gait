#ifndef SERVOCLASS_H
#define SERVOCLASS_H


//定义舵机类
class MyServo {
  public:
    MyServo();  //构造函数
    int si, sj, num; //舵机编号si，sj，对应驱动板上接口num
    int angle;  //舵机角度
    int SERVOMIN, SERVOMAX; //舵机最大最小脉冲
    void setServoPWM(int mi, int ma); //设置舵机脉冲范围
    void changle(int ang);        //舵机改变到ang角度，绝对
    void addangle(int ang);       //舵机转过多少角度，相对
    void printInfor();            //打印舵机数据
};


#endif
