
#pragma once
#include "cocos2d.h"
#include "StartMenu.h"
#include "Level.h"

enum class GameState {
  DEFAULT,
  MAIN_MENU,
  PLAY
};

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float t);

    CREATE_FUNC(HelloWorld);
private:
  Player *m_pPlayer;
  ControllerManager *m_pControllerManager;
  StartMenu *m_pStartMenu;
  Level *m_pLevel;

  GameState m_CurrentGameState;
};