//
// Created by Vlad on 05.09.2020.
//

#include "ControllerManager.h"

ControllerManager *ControllerManager::create(const std::function<void(Ref *)> &func) {
  ControllerManager *node = new (std::nothrow)ControllerManager();
  if (node && node->init(func))
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool ControllerManager::init(const std::function<void(Ref *)> &func) {
  initLeftButton();
  initRightButton();

  m_MainFunc = func;
  m_CurrentState = ControllerManagerState::NONE;

  return true;
}

void ControllerManager::initLeftButton() {
  auto screenOrigin = cocos2d::Director::getInstance()->getVisibleOrigin();
  auto screenSize = cocos2d::Director::getInstance()->getVisibleSize();

  m_pLeftButton = Button::create("Buttons/Triangle.png", cocos2d::Color3B::GRAY, [this](cocos2d::Ref *sender) {
    m_CurrentState = ControllerManagerState::LEFT_BUTTON_PRESSED;

    if (m_MainFunc != nullptr) {
      m_MainFunc(this);
    }
  });
  m_pLeftButton->setPosition(screenOrigin.x + screenSize.width / 8.0f,
    screenOrigin.y + screenSize.height / 8.0f);

  this->addChild(m_pLeftButton);
}

void ControllerManager::initRightButton() {
  auto screenOrigin = cocos2d::Director::getInstance()->getVisibleOrigin();
  auto screenSize = cocos2d::Director::getInstance()->getVisibleSize();

  m_pRightButton = Button::create("Buttons/Triangle.png", cocos2d::Color3B::GRAY, [this](cocos2d::Ref *sender) {
    m_CurrentState = ControllerManagerState::RIGHT_BUTTON_PRESSED;

    if (m_MainFunc != nullptr) {
      m_MainFunc(this);
    }
  });
  m_pRightButton->setPosition(screenOrigin.x + screenSize.width - screenSize.width / 8.0f,
    screenOrigin.y + screenSize.height / 8.0f);
  m_pRightButton->runAction(cocos2d::RotateBy::create(0, -180));

  this->addChild(m_pRightButton);
}