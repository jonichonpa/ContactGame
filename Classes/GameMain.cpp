//
//  GameMain.cpp
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/01.
//
//

#include "GameMain.h"
#include "NextWorldScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

const int LAND = 100;

cocos2d::Scene* GameMain::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
    auto scene = Scene::createWithPhysics();
    
    Vect gravity;
    gravity.setPoint(0, -50);
    scene->getPhysicsWorld()->setGravity(gravity);
    scene->getPhysicsWorld()->setSpeed(6.0f);
    
    // 'layer' is an autorelease object
    auto layer = GameMain::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameMain::init()
{
    player = Player::create();
    this->addChild(player);
    
    srand((unsigned)time(nullptr));
    
    // 背景
    dust1 = Sprite::create("bg_front_spacedust.png");
    dust1->setPosition(Point(0,0));
    dust1->setScale(1.0f, 2.0f);
    dust2 = Sprite::create("bg_front_spacedust.png");
    dust2->setPosition(Point(600,0));
    dust2->setScale(1.0f, 2.0f);
    this->addChild(dust1);
    this->addChild(dust2);
    // 定期処理 updateメソッドの実行
    this->scheduleUpdate();
    
    // 地面
    land1 = Sprite::create("land.png");
    land1->setScale(500.0f, 1.0f);
    land1->setPosition(200.0f, 0.0f);
    land1->setTag(LAND);
    auto pb2 = PhysicsBody::createBox(Size(land1->getContentSize().width, land1->getContentSize().height));
    //log("%f,%f",size.width,size.height);
    pb2->setEnable(true);
    pb2->setAngularVelocityLimit(150.0f);
    pb2->setDynamic(false);
    pb2->setContactTestBitmask(0xFFFFFFFF);
    pb2->setTag(LAND);
    land1->setPhysicsBody(pb2);
    
    this->addChild(land1);
    
    // 点描画
    //this->schedule(GameMain::scroll, 0.1f);
    /*DrawNode *node = DrawNode::create();
    node->drawDot(Point(50,50), 50.0f, Color4F(150, 150, 150, 1));
    this->addChild(node);*/
    
    // 線描画
    /*Color4F yellow = Color4F(Color3B::BLUE);
    DrawNode *node = DrawNode::create();
    node->drawSegment(Point(0,0), Point(500, 500), 10, yellow);*/
    //this->addChild(node);
    
    // 多角形描画
    /*DrawNode *node2 = DrawNode::create();
    Point triangle[3] = {Point(150, 200), Point(100, 100), Point(200, 100)};
    node2->drawPolygon(triangle, 4, Color4F(100, 100, 100, 1), 5, Color4F(100,100,100,1));
    this->addChild(node2);*/
    
    // イベントリスナー
    auto tapListener = EventListenerTouchOneByOne::create();
    tapListener->onTouchBegan = CC_CALLBACK_2(GameMain::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(tapListener, this);
    
    // 衝突検知
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameMain::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;
}

bool GameMain::onContactBegin(PhysicsContact& contact)
{
    auto sp = (Sprite*)contact.getShapeA()->getBody()->getNode();
    auto sp2 = (Sprite*)contact.getShapeB()->getBody()->getNode();
    if(sp->getTag() == LAND || sp2->getTag() == LAND) return true;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    
    Scene *next = MenuScene::createScene();
    Director *director = Director::getInstance();
    director->replaceScene(next);
    log("contact");
	return true;
}

void GameMain::update(float delta){
    
    this->dust1->setPositionX(this->dust1->getPositionX() - 2.0f);
    this->dust2->setPositionX(this->dust1->getPositionX() + this->dust1->getContentSize().width - 2.0f);
    
    if (this->dust2->getPositionX() == 0){
        this->dust1->setPositionX(0);
    }
    
    moveEnemy();
}

void GameMain::moveEnemy()
{
    // 敵の移動と消去
    for(Enemy *enemy : enemies){
        //enemy->move();
        if (enemy->getPositionX() == 0) {
            enemy->removeFromParent();
        }
    }
    
    // 敵の出現
    if (rand()%30 == 1)
	{
        Enemy *enemy = Enemy::create();
        enemy->setPosition(1000, rand() % 400 + 100);
        enemies.pushBack(enemy);
        this->addChild(enemy);
        enemy->moveSine();
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("teresa.wav");
	}
}

void GameMain::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool GameMain::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    player->getPhysicsBody()->applyImpulse(Vect(0, 180.0f),Point(0,player->getContentSize().height*-1));
    return true;
}
