#include "Game.h"
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,700);
    setBackgroundBrush(QBrush(QImage(":/img/1.jpg")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,700);

    player = new Player();
    player->setPos(200,580);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    show();
}
