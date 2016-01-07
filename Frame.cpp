#ifndef FRAME
#define FRAME
/*
class WorldFrame{
	
};

class JointFrame{

};
*/

class TaskFrame{                                            //工件坐标系
	pravite:
		double x;                                           //与世界坐标系偏移量x,y与旋转角度deg
		double y;
		double deg;
	public:
		TaskFrame(double a=0,double b=0,double d=0);         
		void SetTaskFrame(double a,double b,double d);      //设置工件坐标系
		double GetX();                                      //获取X方向偏移量x
		double GetY();                                      //获取Y方向偏移量y
		double GetDeg();                                    //获取旋转角度deg
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
