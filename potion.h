#ifndef POTION_H
#define POTION_H

#include<QString>
#include <QGraphicsPixmapItem>

class Potion: public QGraphicsPixmapItem
{
public:
    Potion();
    virtual int getDamageIncrease() const;
    virtual void setDamageIncrease(int value);

    virtual int getHealthIncrease() const;
    virtual void setHealthIncrease(int value);

    virtual QString getName() = 0;
    virtual void setName(const QString &value);

    virtual QString getImage();

    virtual void setImage(QString value);

    static Potion *potionFactory(int choice);

private:
    int damageIncrease;
    int healthIncrease;
    QString image;

protected:
    QString name;
};

#endif // POTION_H
