#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "potion.h"

class HealthPotion : public Potion
{
public:
    HealthPotion();
    QString getName();
};

#endif // HEALTHPOTION_H
