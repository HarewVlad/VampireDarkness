#include "cocos2d.h"
#include "Player.h"
#include "ControllerManager.h"

enum class LevelComponents {
  DEFAULT,
  BACKGROUND,
  PLAYER,
  CONTROLLERS
};

enum class LevelState {
  DEFAULT,
  PLAY,
  GAME_OVER
};

class Level : public cocos2d::Scene {
public:
  static Level *create(const std::function<void(Ref *)> &func);
  bool init(const std::function<void(Ref*)> &func);
  inline constexpr LevelState getState() const {
    return m_CurrentLevelState;
  }

private:
  Player *m_pPlayer;
  ControllerManager *m_pControllerManager;

  cocos2d::Sprite *m_pBackground;
  std::function<void(Ref*)> m_MainFunc;

  LevelState m_CurrentLevelState;
};