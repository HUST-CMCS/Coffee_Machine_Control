#ifndef FRAME
#define FRAME
/*
class WorldFrame{
	
};

class JointFrame{

};
*/

class TaskFrame{                                            //��������ϵ
	pravite:
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
TaskFrame::TaskFrame(double a,double b,double d){
	x=a;
	y=b;
	deg=d;
}
void TaskFrame::SetTaskFrame(double a,double b,double d){
	x=a;
	y=b;
	deg=d;	
}
double TaskFrame::GetX(){
	return x;
}
double TaskFrame::GetY(){
	return y;
}
double TaskFrame::GetDeg(){
	return deg;
}

#endif
