#ifndef DAMAGEPOTION_H
#define DAMAGEPOTION_H

#include "potion.h"

class DamagePotion : public Potion
{
public:
    DamagePotion();
    QString getName();
};

#endif // DAMAGEPOTION_H
