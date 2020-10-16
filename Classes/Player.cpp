#include "Player.h"

Player *Player::create() {
  Player *node = new (std::nothrow)Player();
  if (node && node->init())
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool Player::init() {
  m_pMainSprite = cocos2d::Sprite::create(Config::PLAYER_SOURCE_DIR + Config::PLAYER_MAIN_SPRITE_SOURCE);

  // Idle animation
  cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(
    Config::PLAYER_IDLE_ANIMATION_DIR + Config::PLAYER_ANIMATION_SOURCE);

  auto frames = getSpriteFrames((Config::PLAYER_IDLE_ANIMATION_FORMAT).c_str(),
    Config::PLAYER_IDLE_ANIMATION_FRAMES_COUNT);
  auto animation =
    cocos2d::Animation::createWithSpriteFrames(frames, 1 / static_cast<float>(Config::PLAYER_IDLE_ANIMATION_FRAMES_COUNT));
  animation->retain();

  m_Animations[static_cast<int>(PlayerState::IDLE)] = animation;

  // Set initial state
  setIdleState();

  addChild(m_pMainSprite);
  return true;
}

void Player::setIdleState() {
  if (m_CurrentState != PlayerState::IDLE) {
    m_CurrentState = PlayerState::IDLE;

    // Start animation
    m_pMainSprite->stopAllActions();
    auto animation = m_Animations[static_cast<int>(PlayerState::IDLE)];
    auto animate = cocos2d::Animate::create(animation);
    m_pMainSprite->runAction(cocos2d::RepeatForever::create(animate));
  }
}

void Player::setWalkState() {
 // ...
}