//
//  MenuScene.cpp
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/02.
//
//

#include "MenuScene.h"
#include "GameMain.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello Next World", "Arial", 34);
    
    // position the label on the center of the screen
    //label->setPosition(Point(origin.x + visibleSize.width/2,
     //                        origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    auto titleLabel = LabelTTF::create("テレサに当たったら駄目ゲーム", "Times", 40);
    titleLabel->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(titleLabel);
    
    auto startLabel = LabelTTF::create("ここをタップでスタート!!", "Arial", 34);
    MenuItemLabel *menuItemLabel = MenuItemLabel::create(startLabel, CC_CALLBACK_0(MenuScene::start,this));
    menuItemLabel->setPosition(Point(origin.x + visibleSize.width/2, 200));
    
    auto menu = Menu::create(closeItem, menuItemLabel, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    return true;
}

void MenuScene::start()
{
    Scene *game = GameMain::createScene();
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("mario.wav");
    Director::getInstance()->replaceScene(game);
}

void MenuScene::menuCloseCallback(Ref* pSender)
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
