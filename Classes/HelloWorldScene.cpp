#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // My code
    m_pPlayer = Player::create();
    m_pPlayer->setPosition(origin + visibleSize * 0.5f);

    // Controller
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

    m_pStartMenu = StartMenu::create([this](cocos2d::Ref *sender) {
      switch (m_pStartMenu->getState()) {
      case StartMenuState::PLAY:

        break;
      case StartMenuState::ABOUT:
        break;
      }
    });
    m_pStartMenu->retain();

    scheduleUpdate();

    addChild(m_pControllerManager);
    addChild(m_pPlayer);
    return true;
}

void HelloWorld::update(float t) {
  if (m_CurrentGameState != GameState::MAIN_MENU) {
    Director::getInstance()->pushScene(cocos2d::TransitionFade::create(
      0.5, m_pStartMenu, cocos2d::Color3B(0, 0, 0)));
  }
}