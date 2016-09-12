#include "damagepotion.h"

DamagePotion::DamagePotion()
{
    this->setDamageIncrease(10);
    this->setHealthIncrease(0);
    this->setName("Damage Potion");
    this->setImage(":/images/bigkb_red");
}

QString DamagePotion::getName(){
    return name;
}
