#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease(int amount);
    int getHealth();
    void increase(int amount);
    void setHealth(int amount);

private:
    int health;
};

#endif // HEALTH_H
