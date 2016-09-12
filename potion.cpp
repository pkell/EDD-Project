#include "potion.h"
#include "healthpotion.h"
#include "damagepotion.h"
#include "superhealthpotion.h"

Potion::Potion()
{

}

int Potion::getDamageIncrease() const
{
    return damageIncrease;
}

void Potion::setDamageIncrease(int value)
{
    damageIncrease = value;
}

int Potion::getHealthIncrease() const
{
    return healthIncrease;
}

void Potion::setHealthIncrease(int value)
{
    healthIncrease = value;
}


void Potion::setName(const QString &value)
{
    name = value;
}

QString Potion::getImage()
{
    return image;
}

void Potion::setImage(QString value)
{
    image=value;
}

Potion *Potion::potionFactory(int choice)
{
    switch(choice)
    {
    case 0 :
       return new HealthPotion();
       break;
    case 1:
        return new DamagePotion();
        break;
    case 2:
        return new SuperHealthPotion();
        break;
    default:
        break;
    }
}
