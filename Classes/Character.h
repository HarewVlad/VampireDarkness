#pragma once
#include "cocos2d.h"

class Character : public cocos2d::Node {
public:
  virtual bool init() = 0;
  void addAnimation(int key, cocos2d::Animation *animation);
  void moveUp(float amount);
  void moveDown(float amount);
protected:
  virtual void setIdleState() = 0;
  virtual void setWalkState() = 0;
protected:
  cocos2d::Sprite *m_pMainSprite;
    
  std::unordered_map<int, cocos2d::Animation *> m_Animations;
};