#pragma once

#include "cocos2d.h"
#include "Button.h"

class Menu : public cocos2d::Scene {
public:
  virtual bool init(const std::function<void(Ref *)> &func) = 0;
protected:
  cocos2d::Sprite *m_pBackground;

  std::function<void(Ref *)> m_MainFunc;
};