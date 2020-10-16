#pragma once

#include "cocos2d.h"
#include "Button.h"

class Menu : public cocos2d::Scene {
public:
  virtual bool init(const std::function<void(Ref *)> &func) = 0;
  void addButton(int key, Button *button);
protected:
  cocos2d::Sprite *m_pBackground;
  std::unordered_map<int, Button *> m_Buttons;

  std::function<void(Ref *)> m_MainFunc;
};