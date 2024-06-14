#include "UI.hpp"
#include <iostream>
#include <string>
#include <fstream>

UI::UI() {}

UI::~UI() {}

void UI::Display_Message(const std::string &message)
{
    std::cout << message;
}

void UI::Display_Help_Game()
{
    std::ifstream in("Description.txt", std::ios::in);
    std::string line;
    if (in.is_open())
        while (std::getline(in, line))
            std::cout << line << std::endl;
    else
        std::cerr << "Error opening file !" << std::endl;

    std::cout << std::endl << "For more information, read the file below " << std::endl << "https://roomizgames.ir/wp-content/uploads/2019/08/Rakab_Rules.pdf" << std::endl;
}