#include "scene.h"
#include "room.h"
#include "player.h"
#include <QDebug>
#include "superhealthpotion.h"
#include "crown.h"
#include "chalice.h"
#include "vampirelord.h"
#include "chest.h"
#include "cstdlib"
#include <ctime>
#include <qdebug.h>

Room* Scene::getStart() const
{
    return a;
}

Scene::Scene() : QGraphicsScene()
{
    srand(time(NULL));
    int randNum = rand() % 3;
    a = new Room(0,0, "a", NULL, NULL, NULL);
    a->setPen( QPen( Qt::red ) );
    addItem(a);

    Monster *mB = Monster::monsterFactory(randNum);
    addItem(mB);
    randNum = rand() % 3;
    Potion *pB = Potion::potionFactory(randNum); //potion and monster objects deleted after use in Player class
    treasure *tB = new Chalice();
    addItem(pB);
    addItem(tB);
    b = new Room(100,0, "b", mB, pB,tB);
    b->setPen( QPen( Qt::red ) );
    addItem(b);

    randNum = rand() % 3;
    Monster *mC = Monster::monsterFactory(randNum);
    addItem(mC);
    treasure *tC = new Crown();
    addItem(tC);
    randNum = rand() % 3;
    Potion *pC = Potion::potionFactory(randNum);
    addItem(pC);
    Room *c = new Room(200,0, "c", mC, pC,tC);
    c->setPen( QPen( Qt::red ) );
    addItem(c);

    randNum = rand() % 3;
    Monster *mD = Monster::monsterFactory(randNum);
    addItem(mD);
    randNum = rand() % 3;
    Potion *pD = Potion::potionFactory(randNum);
    addItem(pD);
    treasure *tD = new Chalice();
    addItem(tD);
    d = new Room(0,100, "d", mD, pD, tD);
    d->setPen( QPen( Qt::red ) );
    addItem(d);

    randNum = rand() % 3;
    Monster *mE = Monster::monsterFactory(randNum);
    addItem(mE);
    randNum = rand() % 3;
    Potion *pE = Potion::potionFactory(randNum);
    addItem(pE);
    treasure *tE = new Crown();
    addItem(tE);
    e = new Room(100,100, "e", mE, pE, tE);
    e->setPen( QPen( Qt::red ) );
    addItem(e);

    randNum = rand() % 3;
    Monster *mF = Monster::monsterFactory(randNum);
    addItem(mF);
    Potion *pF = Potion::potionFactory(randNum);
    addItem(pF);
    treasure *tF= new Crown();
    addItem(tF);
    f = new Room(200,100, "e", mF, pF,tF);
    f->setPen( QPen( Qt::red ) );
    addItem(f);

             //(N, E, S, W)
    a->setExits(NULL, b, d, NULL);
    b->setExits(NULL, c, e, a);
    c->setExits(NULL, NULL, f, b);
    d->setExits(a, e, NULL, NULL);
    e->setExits(b, f, NULL, d);
    f->setExits(c, NULL, NULL, e);

    rooms[0] = a;
    rooms[1] = b;
    rooms[2] = c;
    rooms[3] = d;
    rooms[4] = e;
    rooms[5] = f;
}

Scene::~Scene()
{
    delete a;
    delete b;
    delete d;
    delete f;
    delete e;
    delete c;
    delete g;
}

 Room**::Scene::getRooms(){
    return rooms;
}

 void::Scene::addLastLevel(){
     SuperHealthPotion *pG = new SuperHealthPotion();
     Monster *mG = new VampireLord();
     treasure *tG= new Chest();
     addItem(mG);
     addItem(pG);
     addItem(tG);
     g = new Room(100,200, "g", mG, pG, tG);
     e->setExits(b, f, g, d);
     g->setExits(e, NULL, NULL, NULL);
     g->setPen( QPen( Qt::red ) );
     addItem(g);
 }
