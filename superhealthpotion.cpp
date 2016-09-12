#include "superhealthpotion.h"

SuperHealthPotion::SuperHealthPotion()
{
    this->setHealthIncrease(50);
    this->setDamageIncrease(0);
    this->setName("Super Health Potion");
    this->setImage(":/images/bigkb_yellow");
}

QString SuperHealthPotion::getName(){
    return name;
}
