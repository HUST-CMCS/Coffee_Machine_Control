#ifndef FRAME_H
#define FRAME_H
/*
class WorldFrame{
	
};

class JointFrame{

};
*/

class TaskFrame{                                            //��������ϵ
	private:
		double x;                                           //����������ϵƫ����x,y����ת�Ƕ�deg
		double y;
		double deg;
	public:
		TaskFrame(double a=0,double b=0,double d=0);         
		void SetTaskFrame(double a,double b,double d);      //���ù�������ϵ
		double GetX();                                      //��ȡX����ƫ����x
		double GetY();                                      //��ȡY����ƫ����y
		double GetDeg();                                    //��ȡ��ת�Ƕ�deg
};

#endif
