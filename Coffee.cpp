#include"Coffee.h"

Coffee::Coffee()
{
    CK=Espresso;
    BS=Small;
    BottleNum=1;
    Suger=false;
}

int Coffee::GetBottleNum()
{
    return BottleNum;
}

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

void Coffee::SetBottleNum(int a)
{
    BottleNum=a;
}

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
