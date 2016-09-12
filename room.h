#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsRectItem>
#include <vector>
#include <map>
#include <string>
#include "monster.h"
#include "potion.h"
#include "treasure.h"

using namespace std;

class Room : public QGraphicsRectItem
{
private:
    string description;
    map<string, Room*> exits;
    double x, y;
    string exitString();
    Potion *potion;
    Monster *monster;
    treasure *treasures;
public:
    void setExits(Room *north, Room *east, Room *south, Room *west);
    ~Room();
    string shortDescription();
    Room* nextRoom(string direction);
    Room(double x, double y, string description, Monster *m, Potion *p, treasure *t);
    double getX() const;
    double getY() const;
    Potion *getPotion() const;
    void setPotion(Potion *value);
    Monster *getMonster() const;
    void setMonster(Monster *value);
    treasure *getTreasure() const;
    void setTreasure(treasure *value);
    void showMonster();
};

#endif // ROOM_H
