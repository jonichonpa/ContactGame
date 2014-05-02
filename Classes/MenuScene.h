//
//  MenuScene.h
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/02.
//
//

#ifndef __myProject__Menu__
#define __myProject__Menu__

#include <cocos2d.h>

class MenuScene : cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void start();
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

};

#endif /* defined(__myProject__Menu__) */
