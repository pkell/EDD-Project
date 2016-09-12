#include "health.h"

#include <QFont>
#include <QDebug>
#define HEALTH 200
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = HEALTH;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(int amount){
    health -= amount;
    if(health < 0){
        health = 0;
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}

void Health::increase(int amount){
    health += amount;
    setPlainText(QString("Health: ") + QString::number(health));
}


