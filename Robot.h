#ifndef ROBOT_H
#define ROBOT_H
#include "Solver.h"
#include "SetCoffee.h"
TaskFrame WaterFrame(1,1,0);
TaskFrame CupFrame(2,2,pi/6);
TaskFrame MaterialFrame(3,3,pi/3);

class Robot
{
private:
    Setcoffee setcof;  //定义一个求解器类
    int num;           //原料种类数-1
public:
    void Process(Coffee cof);   //根据咖啡对象开始处理，得到原料和杯子的坐标数组，并得到坐标的个数
    void GetAngle(int i,double* Angle);      //根据序号返回原料和杯子的坐标
    int Getnum();               //返回原料种类数-1
};
void Robot::Process(Coffee cof)
{
    int i=0;
    setcof.setC(cof);
    setcof.setpcoffee();
    for(i=2;i<=6;i++)
    {
        if((setcof.getpcoffee()[i].getpx()==0)&&(setcof.getpcoffee()[i].getpy()==0))break;
    }
    num=i-1;
}
void Robot::GetAngle(int i,double* Angle)
{
    Solver sol;
    sol.setpt(setcof.getpcoffee()[i]);
    if(0==i)
        sol.setpt(WaterFrame);
    else if(1==i)
        sol.setpt(CupFrame);
    else
        sol.setpt(MaterialFrame);
    sol.trans();
    sol.antisolve();
    Angle[0]=sol.getang1();
    Angle[1]=sol.getang2();
}
int Robot::Getnum()
{
    return num;
}

#endif
