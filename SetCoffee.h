#ifndef SETCOFFEE_H
#define SETCOFFEE_H
#include "Frame.h"
#include "Coffee.h"
#include "Point.h"
class Setcoffee
{
	private :

			Coffee C;//用于接收咖啡种类
			Point PCoffee[7];//用于输出工件坐标系里的坐标其中第一个元素为水的坐标，第二个元素为杯子的坐标，
			                 //后面的元素为原料的坐标其中糖（若有）为最后一个，若原料的个数没有占满数组则剩余的元素为（0,0）


	public :
		   Setcoffee()
		   {
		   	for(int i=0;i<7;i++)PCoffee[i].setp(0,0);
		   }

		   void setC(Coffee C1)
		   {
               C=C1;
		   }

		   void setpcoffee()
		   {
			 PCoffee[0].setp(5,9);
             switch (C.GetBottleSize())
             {
             	case 0:
             		PCoffee[1].setp(1,5);
             	break;
             	case 1:
             		PCoffee[1].setp(1,8);
             	break;
				case 2:
             		PCoffee[1].setp(1,10);
             	break;
			 }
			 switch (C.GetCoffeeKind())
			 {
			 	case 0:
			 		if(C.GetSuger())
					{
				    PCoffee[2].setp(5,9);
				    PCoffee[3].setp(8,5);
				    PCoffee[4].setp(5,7);
				    PCoffee[5].setp(7,6);
				    PCoffee[6].setp(9,9);
				    }
				    else
				    {
				    PCoffee[2].setp(5,9);
				    PCoffee[3].setp(8,5);
				    PCoffee[4].setp(5,7);
				    PCoffee[5].setp(7,6);
					}
				break;
				case 1:
					if(C.GetSuger())
					{
				    PCoffee[2].setp(4,6);
				    PCoffee[3].setp(7,6);
				    PCoffee[4].setp(9,9);
				    }
				    else
				    {
				    PCoffee[2].setp(4,6);
				    PCoffee[3].setp(7,6);
					}
				break;
				case 2:
					if(C.GetSuger())
					{
				    PCoffee[2].setp(4,6);
				    PCoffee[3].setp(1,6);
				    PCoffee[4].setp(4,3);
				    PCoffee[5].setp(9,9);
				    }
				    else
				    {
				    PCoffee[2].setp(4,6);
				    PCoffee[3].setp(1,6);
				    PCoffee[4].setp(4,3);
					}
				break;
				case 4:
					if(C.GetSuger())
					{
				    PCoffee[2].setp(3,9);
				    PCoffee[3].setp(8,3);
				    PCoffee[4].setp(9,9);
				    }
				    else
				    {
				    PCoffee[2].setp(3,9);
				    PCoffee[3].setp(8,3);
					}
				break;
				case 5:
					if(C.GetSuger())
					{
				    PCoffee[2].setp(1,9);
				    PCoffee[3].setp(4,3);
				    PCoffee[4].setp(9,9);
				    }
				    else
				    {
				     PCoffee[2].setp(1,9);
				     PCoffee[3].setp(4,3);
					}
				break;
				case 6:
					if(C.GetSuger())
					{
				    PCoffee[2].setp(3,1);
				    PCoffee[3].setp(5,3);
				    PCoffee[4].setp(8,7);
				    PCoffee[5].setp(8,5);
				    PCoffee[6].setp(9,9);
				    }
				    else
				    {
				    PCoffee[2].setp(3,1);
				    PCoffee[3].setp(5,3);
				    PCoffee[4].setp(8,7);
				    PCoffee[5].setp(8,5);
					}
				break;
			 }

		   }

		   Point* getpcoffee()
		   {
		   	  return PCoffee;
		   }

};
#endif
