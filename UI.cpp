#include "UI.hpp"
#include <iostream>
#include <string>

UI::UI() {}

UI::~UI() {}

void UI::Display_Message(const std::string &message)
{
    std::cout << message;
}