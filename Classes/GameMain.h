//
//  GameMain.h
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/01.
//
//

#ifndef __myProject__GameMain__
#define __myProject__GameMain__

#include "cocos2d.h"
#include "Player.h"
#include "Enemy.h"

USING_NS_CC;

class GameMain : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);
    
    // イベントリスナー
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onContactBegin(PhysicsContact& contact);
    
    // 背景スクロール
    void scroll();
    void update(float delta);
    
    // 敵を動かす
    void moveEnemy();
    
private:
    Player *player;
    Sprite *dust1;
    Sprite *dust2;
    Sprite *land1;
    
    Vector<Enemy*> enemies;
    
};

#endif /* defined(__myProject__GameMain__) */
