#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget * parent=0);
    Scene * scene;
    Player * player;
    ~Game();

};

#endif // GAME_H
