//
//  Player.cpp
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/02.
//
//

#include "Player.h"

USING_NS_CC;

Player::Player()
{
}

Player* Player::create()
{
    Player *player = new Player();
    if (player && player->init()){
        player->autorelease();
        return player;
    }
    CC_SAFE_DELETE(player);
    return nullptr;
}

bool Player::init()
{
    this->initWithFile("mario_mini.png");
    //this->setScale(0.2f);
    auto pb = PhysicsBody::createBox(Size(this->getContentSize().width - 10, this->getContentSize().height-20));
    //log("%f,%f",size.width,size.height);
    pb->setEnable(true);
    pb->setMass(1.0f);
    pb->setVelocity(Vect(0,1));
    pb->setVelocityLimit(100.0);
    pb->setRotationEnable(true);
    pb->setAngularVelocityLimit(150.0f);
    pb->setDynamic(true);
    pb->setContactTestBitmask(0xFFFFFFFF);
    this->setPosition(Point(228,708));
    this->setPhysicsBody(pb);
    return true;
}

void Player::update(float delta)
{
}
