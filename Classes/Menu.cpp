#include "Menu.h"

void Menu::addButton(int key, Button *button) {
  assert(button != nullptr, "error: button is nullptr");
  m_Buttons.insert(std::pair<int, Button *>(key, button));
}