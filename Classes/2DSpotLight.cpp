#include "2DSpotLight.h"

SpotLight2D *SpotLight2D::create() {
  SpotLight2D *node = new (std::nothrow)StartMSpotLight2Denu();
  if (node && node->init(func))
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool SpotLight2D::init() {
  return true;
}