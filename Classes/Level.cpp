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
  m_pBackground = cocos2d::Sprite::create(LevelResources::LEVEL_RESOURCES_DIR + "background.png");
  auto backgroundBody = cocos2d::PhysicsBody::createBox(m_pBackground->getContentSize(),
    cocos2d::PhysicsMaterial(0.0f, 0.0f, 1.0f));
  backgroundBody->setDynamic(false);
  m_pBackground->setPhysicsBody(backgroundBody);
  addChild(m_pBackground, static_cast<int>(LevelComponents::BACKGROUND));
  
  // Add lightning
  auto light = cocos2d::AmbientLight::create(cocos2d::Color3B::RED);
  addChild(light, static_cast<int>(LevelComponents::LIGHTNING));

  // Add ...
  

  return true;
}