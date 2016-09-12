#ifndef TREASURE_H
#define TREASURE_H

#include <QString>
#include <QGraphicsPixmapItem>

class treasure: public QGraphicsPixmapItem
{
public:
    treasure();

    int getitemIncrease() const;
    void setitemIncrease(int value);

    QString gettreasureName() const;
    void settreasureName(const QString &value);

    QString getImage();
    void setImage(QString value);


private:
   int itemIncrease;
   QString image;
   QString treasureName;
};

#endif // TREASURE_H
