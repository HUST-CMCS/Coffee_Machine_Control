#ifndef SOLVOER_H
#define SOLVOER_H
#include "Point.h"
#include "Frame.h"
#include "math.h"
#include "Eigen/Dense"
using Eigen::MatrixXd;
const double pi=3.141592653;
class Solver
{
	private :
	Point  p1;//���ڴ�Ź�������ϵ�µ�����ֵ
	Point  p2;//���ڴ����������ϵ�µ�����ֵ
	TaskFrame T1;
	double ang1,ang2;//����õ��ĽǶ�
	double arm1,arm2;//��е���۳�
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
		void trans()//����任����
		{
			double x1,y1,ang;
			x1=T1.GetX();
			y1=T1.GetY();
			ang=T1.GetDeg();
			//��һ��ͬѧ������д�任�������⼰��������ϵ������ֵ����ʵ�֣�����ֵ��P2,���� x1 y1 ang �ǹ�������ϵ�������������ϵ�ı任��
			MatrixXd TF(3,3),P(3,1),NP(3,1);//P��ʾ��������ϵ�µ����꣬NP��ʾͨ���任����ת����ĵ����꣬TFΪ�任����
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
		void antisolve()//���⺯���ɷ�һ��ͬѧʵ��
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
