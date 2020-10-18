#pragma once

#include "Menu.h"

enum class StartMenuState {
  DEFAULT,
  PLAY,
  ABOUT,
  EXIT
};

class StartMenu : public Menu {
public:
  static StartMenu *create(const std::function<void(Ref *)> &func);
  bool init(const std::function<void(Ref *)> &func) override;
  inline constexpr StartMenuState getState() {
    return m_CurrentState;
  }
private:
  StartMenuState m_CurrentState;
};