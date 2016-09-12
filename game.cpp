#include "game.h"
#include <QImage>

Game::Game(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    scene = new Scene();
    scene->setSceneRect(0,0,500,300);
    player = new Player(scene);
    scene->addItem(player);
    setBackgroundBrush(QBrush(QImage(":/images/wood")));
    setScene(scene);
    show();
}

Game::~Game()
{
    delete player;
    delete scene;
}
