#pragma once

#include "cocos2d.h"

class Skeleton : public cocos2d::Node {
public:
  Skeleton *create(const std::function<void(Ref*)> &func);
  bool init(const std::function<void(Ref*)> &func);
};