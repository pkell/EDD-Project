#include "room.h"


Room::Room(double x, double y, string description, Monster *m, Potion *p,treasure *t) : QGraphicsRectItem()
{
    this->description = description;
    this->x = x;
    this->y = y;
    monster = m;
    potion = p;
    treasures=t;
    setRect(x,y, 100, 100);

}

double Room::getX() const
{
    return x;
}

double Room::getY() const
{
    return y;
}

Potion *Room::getPotion() const
{
    return potion;
}

void Room::setPotion(Potion *value)
{
    potion = value;
}

Monster *Room::getMonster() const
{
    return monster;
}

void Room::setMonster(Monster *value)
{
    monster = value;
}

treasure *Room::getTreasure() const
{
    return treasures;
}

void Room::setTreasure(treasure *value)
{
    treasures = value;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

Room::~Room()
{
    delete potion;
    delete treasures;
    delete monster;
}

string Room::shortDescription() {
    return description;
}

void Room:: showMonster()
{
    monster->setPixmap(monster->getImage());
    monster->setPos(this->x+50,this->y);
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}
