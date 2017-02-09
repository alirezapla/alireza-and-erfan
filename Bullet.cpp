#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "Game.h"


extern Game * RiverRaid;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    QPixmap playerIcon(":/img/bullet.png");
    QPixmap resize = playerIcon.scaled(QSize(60,60) ,Qt::KeepAspectRatio);
    setPixmap(resize);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    qDebug("constractor");
}

Bullet::~Bullet(){
    qDebug("destructor");
    scene()->removeItem(this);
}

void Bullet::move(){
    qDebug("move");
    setPos(x(),y()-10);
    if (pos().y() < 0){
        qDebug("if state");
        delete this;
    }
}
