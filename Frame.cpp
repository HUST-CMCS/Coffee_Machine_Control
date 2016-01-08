#include"Frame.h"
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
