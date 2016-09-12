#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "scene.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMessageBox>
#include "health.h"
#include "room.h"
#include <treasurecount.h>

class Player : public QGraphicsPixmapItem
{
private:
    QMessageBox monsterMsgBox;
    QMessageBox msgBox;
    QPushButton *attackButton;
    QPushButton *fleeButton;
    Scene *sc;
    Health *h;
    TreasureCount *tc;
    int damage;
    Room *currentRoom;
public:
    Player(Scene *s);
    void keyPressEvent(QKeyEvent * event);
    void monsterInteraction();
    void potionInteraction();
    void treasureInteraction();
    void teleport();
    Health *getH() const;
    void setH(Health *value);
    void loserPopup();
    ~Player();
};

#endif // PLAYER_H
