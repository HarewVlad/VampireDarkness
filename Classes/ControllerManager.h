//
// Created by Vlad on 05.09.2020.
//

#ifndef PROJ_ANDROID_CONTROLLERMANAGER_H
#define PROJ_ANDROID_CONTROLLERMANAGER_H

#include "Button.h"
#include "cocos2d.h"

enum class ControllerManagerState {
  NONE,
  LEFT_BUTTON_PRESSED,
  RIGHT_BUTTON_PRESSED
};

class ControllerManager : public cocos2d::Node {
public:
  static ControllerManager *create(const std::function<void(Ref *)> &func);
  bool init(const std::function<void(Ref *)> &func);
  inline constexpr ControllerManagerState getState() {
    return m_CurrentState;
  }
 private:
  void initRightButton();
  void initLeftButton();

 public:
   Button *m_pRightButton;
   Button *m_pLeftButton;

   std::function<void(Ref *)> m_MainFunc;

   ControllerManagerState m_CurrentState;
};

#endif  // PROJ_ANDROID_CONTROLLERMANAGER_H
