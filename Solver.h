#ifndef SOLVER_H
#define SOLVER_H
#include "Point.h"
#include "Frame.h"
#include "math.h"
#include "Eigen/Dense"
using Eigen::MatrixXd;
const double pi=3.141592653;
class Solver
{
	private :
	Point  p1;//用于存放工件坐标系下的坐标值
	Point  p2;//用于存放世界坐标系下的坐标值
	TaskFrame T1;
	double ang1,ang2;//反解得到的角度
	double arm1,arm2;//机械各臂长
	public :
	    Solver()
	    {
	        arm1=arm2=100;
	        p1.setp(0,0);
	        T1.SetTaskFrame(0,0,0);
	    }
		void setpt(Point  p, TaskFrame T)
		{
			p1=p;
			T1=T;
		}
		void setpt(Point p)
		{
		    p1=p;
		}
		void setpt(TaskFrame T)
		{
		    T1=T;
		}
		void trans()//坐标变换函数
		{
			double x1,y1,ang;
			x1=T1.GetX();
			y1=T1.GetY();
			ang=T1.GetDeg();
			//冯一飞同学在下面写变换矩阵的求解及世界坐标系下坐标值求解的实现，并幅值给P2,其中 x1 y1 ang 是工件坐标系相对于世界坐标系的变换量
			MatrixXd TF(3,3),P(3,1),NP(3,1);//P表示工件坐标系下点坐标，NP表示通过变换矩阵转换后的点坐标，TF为变换矩阵
			TF(0,0)=cos(ang);
			TF(0,1)=sin(ang);
			TF(0,2)=-x1;
			TF(1,0)=-sin(ang);
			TF(1,1)=cos(ang);
			TF(1,2)=-y1;
			TF(2.0)=TF(2,1)=0;
			TF(2,2)=1;
			P(0,0)=p1.getpx();
			P(1,0)=p1.getpy();
			P(2,0)=1;
			NP=TF*P;
			p2.setp(NP(0,0),NP(1,0));
		}
		void antisolve()//反解函数由冯一飞同学实现
		{
			double theta;
			double x,y,l;
			x=p2.getpx();
			y=p2.getpy();
			l=abs(sqrt(x*x+y*y));
			theta=atan2(y,x)/pi*180;
			ang1=theta+acos((-arm2*arm2+arm1*arm1+l*l)/(2*arm1*l))/pi*180;
			ang2=acos((-l*l+arm1*arm1+arm2*arm2)/(2*arm1*arm2))/pi*180+180;
		}
		Point getp2()
		{
			return p2;
		}
		double getang1()
		{
			return ang1;
		}
		double getang2()
		{
			return ang2;
		}
};
#endif
