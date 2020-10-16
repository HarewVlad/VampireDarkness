#include "Character.h"

void Character::addAnimation(int key, cocos2d::Animation *animation) {
  assert(animation != nullptr, "error: animation is nullptr");
  m_Animations.insert(std::pair<int, cocos2d::Animation *>(key, animation));
}

void Character::moveUp(float amount) {
  runAction(cocos2d::MoveBy::create(1, { 0, amount }));

  setWalkState();
}

void Character::moveDown(float amount) {
  runAction(cocos2d::MoveBy::create(1, { 0, -amount }));

  setWalkState();
}