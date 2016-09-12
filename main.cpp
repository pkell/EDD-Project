#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include "game.h"
#include <qdebug.h>

/*
 * ZorkChops Team
 * Paul Kelly
 * Joel Hartney
 * */
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Game *game = new Game();
    game->show();
    return app.exec();
}
