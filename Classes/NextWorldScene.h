//
//  NextWorldScene.h
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/01.
//
//

#ifndef __myProject__NextWorldScene__
#define __myProject__NextWorldScene__

#include "cocos2d.h"

class NextWorld : public cocos2d::Layer
{
    public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(NextWorld);
};

#endif /* defined(__myProject__NextWorldScene__) */
