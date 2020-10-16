#pragma once

#include "Menu.h"

enum class StartMenuState {
  DEFAULT,
  PLAY,
  ABOUT
};

class StartMenu : public Menu {
public:
  static StartMenu *create(const std::function<void(Ref *)> &func);
  bool init(const std::function<void(Ref *)> &func) override;
  constexpr inline StartMenuState getState() {
    return m_CurrentState;
  }
private:
  StartMenuState m_CurrentState;
};