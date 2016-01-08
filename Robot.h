#ifndef ROBOT_H
#define ROBOT_H
#include "Solver.h"

class Robot
{
private:
    Setcoffee setcof;  //定义一个求解器类
    int num;           //原料种类数-1
public:
    void Process(Coffee cof);   //根据咖啡对象开始处理，得到原料和杯子的坐标数组，并得到坐标的个数
    Point GetPoint(int i);      //根据序号返回原料和杯子的数组
    int Getnum();               //返回原料种类数-1
};
void Robot::Process(Coffee cof)
{
    int i=0;
    setcof.setC(cof);
    setcof.setP();
    for(;i<=6;i++)
    {
        if((setcof.getpcoffee[i].getpx()==0)&&(setcof.getpcoffee[i].getpy()==0))break;
    }
    num=i-1;
}
Point Robot::GetPoint(int i)
{
    return setcof.getpcoffee[i];
}
int Robot::Getnum()
{
    return num;
}

#endif
