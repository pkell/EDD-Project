#include "treasure.h"

treasure::treasure()
{
}
    int treasure::getitemIncrease() const
    {
      return itemIncrease;
    }

    void treasure::setitemIncrease(int value)
    {
        itemIncrease=value;
    }

    QString treasure::gettreasureName() const
    {
        return treasureName;
    }

    void treasure::settreasureName(const QString &value)
    {
        treasureName=value;
    }

    QString treasure::getImage()
    {
        return image;
    }

    void treasure::setImage(QString value)
    {
        image=value;
    }



