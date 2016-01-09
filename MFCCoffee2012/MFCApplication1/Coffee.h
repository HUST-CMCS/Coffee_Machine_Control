#ifndef COFFEE_H
#define COFFEE_H

enum CoffeeKind
{
Mocha=0,//摩卡
Latte=1,//拿铁
Cappuccino=2,//卡布基诺
Americano=3,//美式咖啡
Espresso=4,//意式咖啡
Milkcoffee=5,//奶咖
Foam=6//奶沫
};

enum BottleSize
{
    Small=0,
    Middle=1,
    Large=2
};

class Coffee
{
private:
	CoffeeKind CK;
	BottleSize BS;
//	int BottleNum;
	bool Suger;
//	int Concentration;
public:
	Coffee();
	Coffee(CoffeeKind CK,BottleSize BS,bool Suger);
	void SetCoffeeKind(CoffeeKind a);
	CoffeeKind GetCoffeeKind();
	void SetBottleSize(BottleSize a);
	BottleSize GetBottleSize();
//	void SetBottleNum(int a);
//	int GetBottleNum();
	void SetSuger(bool a);
	bool GetSuger();
//	void SetConcentration(int a);
//	int GetConcentration();
};

Coffee::Coffee()
{
    CK=Mocha;
    BS=Small;
//    BottleNum=1;
    Suger=false;
//    Concentration=30;
}
Coffee::Coffee(CoffeeKind ck,BottleSize bs,bool suger){
	CK=ck;
    BS=bs;
    Suger=suger;
}
/*
int Coffee::GetBottleNum()
{
    return BottleNum;
}
*/
BottleSize Coffee::GetBottleSize()
{
    return BS;
}

CoffeeKind Coffee::GetCoffeeKind()
{
    return CK;
}

bool Coffee::GetSuger()
{
    return Suger;
}
/*
int Coffee::GetConcentration()
{
    return Concentration;
}

void Coffee::SetBottleNum(int a)
{
    BottleNum=a;
}
*/
void Coffee::SetBottleSize(BottleSize a)
{
    BS=a;
}

void Coffee::SetCoffeeKind(CoffeeKind a)
{
    CK=a;
}

void Coffee::SetSuger(bool a)
{
    Suger=a;
}
/*
void Coffee::SetConcentration(int a)
{
    Concentration=a;
}
*/
#endif // COFFEE_H
