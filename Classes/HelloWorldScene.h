
#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "ControllerManager.h"
#include "StartMenu.h"

enum class GameState {
  DEFAULT,
  MAIN_MENU
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

  GameState m_CurrentGameState;
};