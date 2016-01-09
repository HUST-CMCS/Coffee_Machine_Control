#ifndef FRAME_H
#define FRAME_H
/*
class WorldFrame{

};

class JointFrame{

};
*/

class TaskFrame{
	private:
		double x;
		double y;
		double deg;
	public:
		TaskFrame(double a=0,double b=0,double d=0);
		void SetTaskFrame(double a,double b,double d);
		double GetX();
		double GetY();
		double GetDeg();
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
