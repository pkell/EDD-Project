#ifndef MONSTER_H
#define MONSTER_H

#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Monster: public QGraphicsPixmapItem
{
public:
    Monster();

    virtual int getDamage() const;

    virtual int getHealth() const;

    virtual void reduceHealth(int attackDamage);

    virtual QString getName();

    virtual void setName(QString value);

    virtual void setDamage(int value);

    virtual void setHealth(int value);

    virtual bool getScareable() const;

    virtual void setScareable(const bool value);

    virtual QString getImage();

    virtual void setImage(QString value);

    static Monster *monsterFactory(int choice);


private:
    int damage;
    QString name;
    int health;
    bool scareable;
    QString image;
};

#endif // MONSTER_H
