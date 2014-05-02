//
//  Player.h
//  myProject
//
//  Created by 遠藤 和樹 on 2014/05/02.
//
//

#ifndef __myProject__Player__
#define __myProject__Player__

#include <cocos2d.h>

class Player : public cocos2d::Sprite
{
public:
    Player();
    
    static Player* create();
    
    void update(float delta);
    bool init();
};

#endif /* defined(__myProject__Player__) */
