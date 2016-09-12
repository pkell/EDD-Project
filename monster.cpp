#include "monster.h"
#include "vampire.h"
#include "vampirelord.h"
#include "rabiddog.h"

Monster::Monster() : QGraphicsPixmapItem()
{

}

int Monster::getDamage() const
{
    return damage;
}

int Monster::getHealth() const
{
    return health;
}

void Monster::reduceHealth(int attackDamage)
{
    health -= attackDamage;
}

QString Monster::getName()
{
    return name;
}

void Monster::setName(QString value){
    name = value;
}

void Monster::setDamage(int value)
{
    damage = value;
}

void Monster::setHealth(int value)
{
    health = value;
}

bool Monster::getScareable() const
{
    return scareable;
}

void Monster::setScareable(const bool value)
{
    scareable = value;
}

QString Monster::getImage()
{
    return image;
}

void Monster::setImage(QString value)
{
    image=value;
}

Monster *Monster::monsterFactory(int choice)
{
    switch(choice)
    {
    case 0 :
       return new Vampire();
       break;
    case 1:
        return new RabidDog();
        break;
    case 2:
        return new VampireLord();
        break;
    default:
        break;
    }
}



