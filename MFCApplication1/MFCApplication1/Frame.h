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
		TaskFrame(double a=0,double b=0,double d=0)
		{
			x=a;
			y=b;
			deg=d;
		}
		void SetTaskFrame(double a,double b,double d)
		{
			x=a;
			y=b;
			deg=d;
		}
		double GetX()
		{
			return x;
		}
		double GetY()
		{
			return y;
		}
		double GetDeg()
		{
			return deg;
		}
};
/*
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
*/
#endif
