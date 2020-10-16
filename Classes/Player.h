#pragma once
#include "cocos2d.h"
#include "Config.h"
#include "Utils.h"
#include "Character.h"

enum class PlayerState {
  DEFAULT,
  IDLE, // TODO(vlad): make different IDLE animations
  WALK
};

class Player : public Character {
public:
  static Player *create();
  bool init() override;
private:
  void setIdleState() override;
  void setWalkState() override;
private:
  PlayerState m_CurrentState;
};