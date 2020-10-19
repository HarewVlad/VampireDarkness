#include "Skeleton.h"

Skeleton *Skeleton::create(const std::function<void(Ref *)> &func) {
  Skeleton *node = new (std::nothrow)Skeleton();
  if (node && node->init(func))
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool Skeleton::init(const std::function<void(Ref *)> &func) {


  return true;
}