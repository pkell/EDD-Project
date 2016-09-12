#include "healthpotion.h"

HealthPotion::HealthPotion()
{
    this->setHealthIncrease(20);
    this->setDamageIncrease(0);
    this->setName("Health Potion");
    this->setImage(":/images/bigkb_yellow");
}

QString HealthPotion::getName(){
    return this->name;
}
