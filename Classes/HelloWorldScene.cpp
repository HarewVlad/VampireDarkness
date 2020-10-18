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

    // Add start menu
    m_pStartMenu = StartMenu::create([this](cocos2d::Ref *sender) {
      switch (m_pStartMenu->getState()) {
      case StartMenuState::PLAY:
        m_CurrentGameState = GameState::PLAY;

        Director::getInstance()->pushScene(cocos2d::TransitionFade::create(
          0.5, m_pLevel, cocos2d::Color3B(0, 0, 0)));
        break;
      case StartMenuState::ABOUT:
        break;
      case StartMenuState::EXIT:
        Director::getInstance()->end();
        break;
      }
    });
    m_pStartMenu->retain();

    // Add level
    m_pLevel = Level::create([this](cocos2d::Ref *sender) {
      switch (m_pLevel->getState()) {
      case LevelState::PLAY:
        break;
      case LevelState::GAME_OVER:
        break;
      }
    });
    m_pLevel->retain();

    scheduleUpdate();

    return true;
}

void HelloWorld::update(float t) {
  if (m_CurrentGameState != GameState::MAIN_MENU) {
    Director::getInstance()->pushScene(cocos2d::TransitionFade::create(
      0.5, m_pStartMenu, cocos2d::Color3B(0, 0, 0)));

    m_CurrentGameState = GameState::MAIN_MENU;
  }
}