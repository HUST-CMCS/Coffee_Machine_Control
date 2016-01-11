#ifndef POINT_H
#define POINT_H
class Point
{
	private :
		double px,py;
	public :

		double getpx()
		{
			return px;
		}
		double getpy()
		{
			return py;
		}
		void setp(double x, double y)
		{
			px=x;
			py=y;
		}
};
#endif
