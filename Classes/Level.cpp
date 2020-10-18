#include "Level.h"

Level *Level::create(const std::function<void(Ref *)> &func) {
  Level *node = new (std::nothrow)Level();
  if (node && node->init(func))
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool Level::init(const std::function<void(Ref *)> &func) {
  // Init vars
  m_MainFunc = func;

  if (!Scene::initWithPhysics()) {
    return false;
  }

  auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
  auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();

  // Add player
  m_pPlayer = Player::create();
  m_pPlayer->setPosition(origin + visibleSize * 0.5f);
  addChild(m_pPlayer, static_cast<int>(LevelComponents::PLAYER));

  // Add controller
  m_pControllerManager = new ControllerManager();
  m_pControllerManager->init([this](cocos2d::Ref *sender) {
    switch (m_pControllerManager->getState()) {
    case ControllerManagerState::LEFT_BUTTON_PRESSED:
    {
      m_pPlayer->moveUp(1.0f);
    }
    break;
    case ControllerManagerState::RIGHT_BUTTON_PRESSED:
    {
      m_pPlayer->moveDown(1.0f);
    }
    break;
    }
  });
  addChild(m_pControllerManager, static_cast<int>(LevelComponents::CONTROLLERS));

  // Add background

  // Add ...

  return true;
}