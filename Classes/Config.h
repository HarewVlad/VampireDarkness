#pragma once
#include "cocos2d.h"

namespace Config {
  static const std::string PLAYER_SOURCE_DIR  = "Player/";
  static const std::string PLAYER_IDLE_ANIMATION_DIR = "Player/Idle/";

  static const std::string PLAYER_NAME = "Vampire";
  static const std::string PLAYER_MAIN_SPRITE_SOURCE = PLAYER_NAME + ".png";
  static const std::string PLAYER_ANIMATION_SOURCE = PLAYER_NAME + ".plist";
  
  static const std::string PLAYER_IDLE_ANIMATION_FORMAT = "Vampire_Idle_%d.png";
  static const int PLAYER_IDLE_ANIMATION_FRAMES_COUNT = 3;
}