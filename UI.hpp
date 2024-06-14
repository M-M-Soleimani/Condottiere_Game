#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>

class UI
{
public:
    UI();
    ~UI();
    void Display_Message(const std::string &);
    template <typename T>
    T Get_User_Input()
    {
        T choice;
        std::cin >> choice;
        return choice;
    }
    void Display_Help_Game();
};

#endif