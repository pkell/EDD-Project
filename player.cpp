#include "player.h"
#include <QDebug>
#include <QString>
#include <QPushButton>
#include "rabiddog.h"
#include "crown.h"
#include "healthpotion.h"
#include "QApplication"

#define SCAREABLE_LIMIT 15

Health *Player::getH() const
{
    return h;
}

void Player::setH(Health *value)
{
    h = value;
}

void Player::loserPopup()
{
    msgBox.setText("You are dead. Game Over.");
    msgBox.setInformativeText("");
    msgBox.exec();
}

Player::~Player()
{
    delete h;
    delete sc;
    delete tc;
    delete currentRoom;
    delete attackButton;
    delete fleeButton;
}

Player::Player(Scene* s) : QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/KnightInTemplarColors"));

    sc = s;
    h = new Health();
    h->setPos(300,0);
    sc->addItem(h);
    tc = new TreasureCount();
    tc->setPos(300, 20);
    sc->addItem(tc);
    damage = 20;
    currentRoom = sc->getStart();
    setFlag(ItemIsFocusable);
    setFocus();
    attackButton = monsterMsgBox.addButton(QObject::tr("Attack"), QMessageBox::ActionRole);
    fleeButton = monsterMsgBox.addButton(QObject::tr("Flee"), QMessageBox::ActionRole);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(h->getHealth() > 0){
        switch(event->key()){
        case Qt::Key_Left:
            if(currentRoom->nextRoom("west") != NULL){
                currentRoom = currentRoom->nextRoom("west");
                setPos(currentRoom->getX(), currentRoom->getY());
                if(currentRoom->getPotion() != NULL){
                    potionInteraction();
                }
                if(currentRoom->getMonster() != NULL){
                    monsterInteraction();
                }
                if(currentRoom->getTreasure()!= NULL){
                    treasureInteraction();
                }
            }
            break;

        case Qt::Key_Right:
            if(currentRoom->nextRoom("east") != NULL){
                currentRoom = currentRoom->nextRoom("east");
                setPos(currentRoom->getX(), currentRoom->getY());
                if(currentRoom->getPotion() != NULL){
                    potionInteraction();
                }
                if(currentRoom->getMonster() != NULL){
                    monsterInteraction();
                }
                if(currentRoom->getTreasure()!= NULL){
                    treasureInteraction();
                }
            }
            break;

        case Qt::Key_Down:
            if(currentRoom->nextRoom("south") != NULL){
                currentRoom = currentRoom->nextRoom("south");
                setPos(currentRoom->getX(), currentRoom->getY());
                if(currentRoom->getPotion() != NULL){
                    potionInteraction();
                }
                if(currentRoom->getMonster() != NULL){
                    monsterInteraction();
                }
                if(currentRoom->getTreasure()!= NULL){
                    treasureInteraction();
                }
            }
            break;

        case Qt::Key_Up:
            if(currentRoom->nextRoom("north") != NULL){
                currentRoom = currentRoom->nextRoom("north");
                setPos(currentRoom->getX(), currentRoom->getY());
                if(currentRoom->getPotion() != NULL){
                    potionInteraction();
                }
                if(currentRoom->getMonster() != NULL){
                    monsterInteraction();
                }
                if(currentRoom->getTreasure()!= NULL){
                    treasureInteraction();
                }
            }
            break;

        case Qt::Key_T:
            teleport();
            break;

        case Qt::Key_Q:
            QApplication::closeAllWindows();
            break;
        default:
            break;
        }
    }
    else{
        loserPopup();
    }
}

void Player::monsterInteraction()
{
    while(currentRoom->getMonster()->getHealth() > 0){
        currentRoom->getMonster()->setPixmap(currentRoom->getMonster()->getImage());
        currentRoom->getMonster()->setPos(currentRoom->getX()+ 50,currentRoom->getY());
        int enemyHealth = currentRoom->getMonster()->getHealth();
        QString desc = "Enemy: " + QString::number(enemyHealth) + "\nYou: " + QString::number(h->getHealth());
        monsterMsgBox.setText(currentRoom->getMonster()->getName());
        monsterMsgBox.setInformativeText(desc);
        monsterMsgBox.exec();
        if(monsterMsgBox.clickedButton() == attackButton){
            currentRoom->getMonster()->setHealth(enemyHealth - damage);
            if(currentRoom->getMonster()->getHealth() < SCAREABLE_LIMIT && currentRoom->getMonster()->getScareable() == true)
            {
                monsterMsgBox.setInformativeText("Enemy has fled!");
                monsterMsgBox.exec();
                break;
            }
            h->decrease(currentRoom->getMonster()->getDamage());
            if(h->getHealth() == 0){
                loserPopup();
                break;
            }
        }
        else{
            teleport();
            break;
        }
    }
    if(currentRoom->getTreasure() != NULL){
        treasureInteraction();
    }
    delete currentRoom->getMonster();
    currentRoom->setMonster(NULL);
}

void Player::potionInteraction()
{
    currentRoom->getPotion()->setPixmap(currentRoom->getPotion()->getImage());
    currentRoom->getPotion()->setPos(currentRoom->getX(),currentRoom->getY()+50);

     msgBox.setText(currentRoom->getPotion()->getName());
     msgBox.setInformativeText("Health + " + QString::number(currentRoom->getPotion()->getHealthIncrease()) + "\nDamage + " + QString::number(currentRoom->getPotion()->getDamageIncrease()));
     h->increase(currentRoom->getPotion()->getHealthIncrease());
     damage += currentRoom->getPotion()->getDamageIncrease();
     msgBox.exec();
     delete currentRoom->getPotion();
     currentRoom->setPotion(NULL);

}

void Player::treasureInteraction()
{
    currentRoom->getTreasure()->setPixmap(currentRoom->getTreasure()->getImage());
    currentRoom->getTreasure()->setPos(currentRoom->getX()+ 45,currentRoom->getY()+75);


    tc->increase();
    msgBox.setText(currentRoom->getTreasure()->gettreasureName());
    msgBox.setInformativeText("Treasure Items + 1");
    msgBox.exec();
    currentRoom->setTreasure(NULL);
    if(tc->getItems() == 5){
        sc->addLastLevel();
    }
}

void Player::teleport()
{
    int randNum;
    randNum = rand() % 6;
    while(currentRoom->shortDescription().compare(sc->getRooms()[randNum]->shortDescription()) == 0){
        randNum = rand() % 6;
    }
    currentRoom = sc->getRooms()[randNum];
    setPos(currentRoom->getX(), currentRoom->getY());
    if(currentRoom->getPotion() != NULL){
        potionInteraction();
    }
    if(currentRoom->getMonster() != NULL){
        monsterInteraction();
    }
}


