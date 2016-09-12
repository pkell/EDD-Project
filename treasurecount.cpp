#include "treasurecount.h"
#include <QFont>

TreasureCount::TreasureCount(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    items = 0;
    setPlainText(QString("Treasure: ") + QString::number(items) + "/5");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void TreasureCount::increase()
{
    items++;
    if(items > 5){
        items--;
    }
    setPlainText(QString("Treasure: ") + QString::number(items) + "/5");
}

int TreasureCount::getItems()
{
    return items;
}

void TreasureCount::setItems(int value)
{
    items = value;
}



