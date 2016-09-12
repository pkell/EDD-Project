#ifndef TREASURECOUNT_H
#define TREASURECOUNT_H

#include <QGraphicsTextItem>

class TreasureCount: public QGraphicsTextItem
{
public:
    TreasureCount(QGraphicsItem * parent=0);
    void increase();
    int getItems();
    void setItems(int value);

private:
    int items;
};

#endif // TREASURECOUNT_H
