#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "room.h"

class Scene : public QGraphicsScene
{
private:
    Room *a, *b, *f, *d, *e, *c, *g;
    Room *rooms[6];
public:
    Scene();
    ~Scene();
    Room** getRooms();
    Room *getStart() const;
    void addLastLevel();
};

#endif // SCENE_H
