#ifndef COFFEE_H
#define COFFEE_H

enum CoffeeKind
{
Espresso=0,
Machiatto=1,
Americano=2,
Flatwhite=3,
CaffeLatte=4,
ConPanna=5,
Cappuccino=6,
CafeMocha=7,
Viennese=8,
CaramelMacchiato=9,
IrishCoffee=10
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
	int BottleNum;
	bool Suger;
public:
	Coffee();
	void SetCoffeeKind(CoffeeKind a);
	CoffeeKind GetCoffeeKind();
	void SetBottleSize(BottleSize a);
	BottleSize GetBottleSize();
	void SetBottleNum(int a);
	int GetBottleNum();
	void SetSuger(bool a);
	bool GetSuger();
};

#endif // COFFEE_H
