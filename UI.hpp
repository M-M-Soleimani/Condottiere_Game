#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Player.hpp"

class UI
{
public:
    UI();                                    // Constructor to create an instance of class UI
    ~UI();                                   // Default distractor
    void Display_Error(const std::string &); // Display the error string
    template <typename T>
    T Get_User_Input() // Template function to get any type of input from the user
    {
        T choice;
        std::cin >> choice;
        std::cin.ignore();
        return choice;
    }
    template <typename T>
    void Display_Message(const T &message) // Template function to display any type of message
    {
        std::cout << message;
    }
    void Display_Game_Help();                                         // Display description to help the player
    void Clear_Window();                                              // Clear the terminal
    std::string Get_Line();                                           // Get a line of string from the user
    char Get_Ch();                                                    // Get a character from the user
    int Get_Number_Of_Player();                                       // Get the number of players from the user, which must be more than 3 and less than 6
    void Get_Player_Informations(std::vector<Player> &, const int &); // Get the information of each player
    void Display_Hand(Player &);                                      // display hand of player
    void Display_Played_Cards(Player &);                              // Display played cards of player
};

#endif