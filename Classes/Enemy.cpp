//
//  Enemy.cpp
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/02.
//
//

#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
}

Enemy* Enemy::create()
{
    Enemy *enemy = new Enemy();
    if (enemy && enemy->init()) {
        enemy->autorelease();
        return enemy;
    }
    CC_SAFE_DELETE(enemy);
    return nullptr;
}

bool Enemy::init()
{
    this->initWithFile("teresa_mini.png");
    this->setPosition(800,0);
    auto pb = PhysicsBody::createBox(Size(this->getContentSize().width-10,this->getContentSize().height-10));
    pb->setEnable(true);
    pb->setMass(1.0f);
    pb->setRotationEnable(false);
    pb->setDynamic(false);
    pb->setContactTestBitmask(0xFFFFFFFF);
    this->setPhysicsBody(pb);
    return true;
}

void Enemy::move()
{
    this->setPositionX(this->getPositionX()-5);
    this->setRotation(this->getRotation()+1);
}

void Enemy::moveSine()
{
    MoveTo *move = MoveTo::create(3.0f, Point(0,this->getPositionY()));
    auto sin = EaseSineInOut::create(move);
    this->runAction(sin);
}

