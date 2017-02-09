#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Bullet.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap playerIcon(":/img/plane2.png");
    QPixmap resize = playerIcon.scaled(QSize(120,120) ,Qt::KeepAspectRatio);
    setPixmap(resize);
    //setPixmap(QPixmap(":/img/plane2.png"));
}


void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > -10)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 490)
        setPos(x()+10,y());
    }

    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y());
        scene()->addItem(bullet);
        // play bulletsound


    }
}
