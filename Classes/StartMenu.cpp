#include "StartMenu.h"

StartMenu* StartMenu::create(const std::function<void(Ref *)> &func) {
  StartMenu *node = new (std::nothrow)StartMenu();
  if (node && node->init(func))
  {
    node->autorelease();
    return node;
  }

  CC_SAFE_DELETE(node);
  return nullptr;
}

bool StartMenu::init(const std::function<void(Ref *)> &func) {
  if (!Scene::init()) {
    return false;
  }

  auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
  auto size = cocos2d::Director::getInstance()->getVisibleSize();

  // Init buttons
  auto playButton = Button::create("Buttons/Rect.png", cocos2d::Color3B::GRAY, [this](cocos2d::Ref *sender) {
    m_CurrentState = StartMenuState::PLAY;

    if (m_MainFunc != nullptr) {
      m_MainFunc(this);
    }
  });
  playButton->setText("Start", cocos2d::Color3B::WHITE);
  playButton->setPosition({ origin.x + size.width * 0.5f, origin.y + size.height * 0.6f });

  auto aboutButton = Button::create("Buttons/Rect.png", cocos2d::Color3B::GRAY, [this](cocos2d::Ref *sender) {
    m_CurrentState = StartMenuState::ABOUT;

    if (m_MainFunc != nullptr) {
      m_MainFunc(this);
    }
  });
  aboutButton->setText("About", cocos2d::Color3B::WHITE);
  aboutButton->setPosition({ origin.x + size.width * 0.5f, origin.y + size.height * 0.5f });

  addButton(static_cast<int>(StartMenuState::PLAY), playButton);
  addButton(static_cast<int>(StartMenuState::ABOUT), aboutButton);
  addChild(playButton);
  addChild(aboutButton);

  return true;
}