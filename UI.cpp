#include "UI.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Player.hpp"
#include "Map.hpp"
#include <algorithm>

#define Red "\u001b[31m"
#define Reset "\u001b[0m"

// Constructor to create an instance of class UI
UI::UI() {}

// Default distractor
UI::~UI() = default;

// Display the error string
void UI::Display_Error(const std::string &error)
{
    std::cerr << Red << error << Reset;
}

// Display description to help the player
void UI::Display_Game_Help()
{
    // Define the input stream from the file and Get game description from file "Description.txt"
    std::ifstream in("Description.txt", std::ios::in);
    std::string line;
    // If the file is opened without any problem, it reads it line by line and displays it in the output
    if (in.is_open())
        while (std::getline(in, line))
            std::cout << line << std::endl;
    // If the file is not opened, an error will be displayed to the user
    else
        std::cerr << "Error opening file !" << std::endl;

    std::cout << std::endl
              << "For more information, read the file below " << std::endl
              << "https://roomizgames.ir/wp-content/uploads/2019/08/Rakab_Rules.pdf" << std::endl;
}

// Clear the terminal
void UI::Clear_Window()
{
    system("cls || clear");
}

// Get a line of string from the user
std::string UI::Get_Line()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Get a character from the user
char UI::Get_Ch()
{
    char character;
    character = getch();
    return character;
}

// Get the number of players from the user, which must be more than 3 and less than 6
int UI::Get_Number_Of_Player()
{
    bool valid = true;
    int number_of_players = 0;
    // As soon as the user enters the number of valid players, it asked for input
    do
    {
        valid = true;
        Display_Message<std::string>("Enter number of players : ");
        number_of_players = Get_User_Input<int>();
        if (number_of_players < 3 || number_of_players > 6)
        {
            valid = false;
            Clear_Window();
            Display_Error("Invalid number of player !(It must be greater than 3 and less than 6)\n");
        }
    } while (!valid);
    return number_of_players;
}

// Get the information of each player
void UI::Get_Player_Informations(std::vector<std::shared_ptr<Player>> &players, const int &number_of_players)
{
    // It takes name, age and input color from each user
    for (size_t i = 0; i < number_of_players; ++i)
    {
        Display_Message<std::string>("player ");
        Display_Message<int>(i + 1);
        Display_Message<std::string>(" : \n");

        Display_Message<std::string>("Enter your name : ");
        std::string name = Get_Line();

        Display_Message<std::string>("Enter your age : ");
        int age = Get_User_Input<int>();

        Display_Message<std::string>("Enter your color : ");
        std::string color = Get_Line();

        std::shared_ptr<Player> temp = std::make_shared<Player>(name, age, color);
        players.push_back(temp);
        Clear_Window();
    }
}

// Display hand of player
void UI::Display_Hand(std::shared_ptr<Player> &player)
{
    Display_Message<std::string>(player->Get_Name());
    Display_Message<std::string>("'s hand : ");
    // It browse the vector of player cards and displays them in a special format
    bool is_first = true;
    for (std::shared_ptr<Card> card : player->Get_hand())
    {
        if (!is_first)
            Display_Message<std::string>(" - ");
        Display_Message<std::string>(card->Get_Type());
        is_first = false;
    }
    Display_Message<std::string>("\n");
}

// Display played cards of player
void UI::Display_Played_Cards(std::shared_ptr<Player> &player)
{
    Display_Message<std::string>(player->Get_Name());
    Display_Message<std::string>("'s played cards : ");
    // It browse the vector of player cards that played in game and displays them in a special format
    bool is_first = true;
    for (std::shared_ptr<Card> card : player->Get_played_crads())
    {
        if (!is_first)
            Display_Message<std::string>(" - ");
        Display_Message<std::string>(card->Get_Type());
        is_first = false;
    }
    Display_Message<std::string>("\n");
}

// Show game information (played cards, conquered provinces, season and battlefield)
void UI::Show_Game_Informations(std::vector<std::shared_ptr<Player>> &players, std::vector<std::shared_ptr<Player>> &players_turn, const int &current_player, const std::string &season, const std::string &battlefield)
{
    for (auto player : players)
    {
        Display_Played_Cards(player);
    }
    Display_Message<std::string>("\n");
    for (auto player : players)
    {
        Display_Acquired_Provinces(player);
    }
    Display_Message<std::string>("\n");
    Display_Message<std::string>("battlefield : ");
    Display_Message<std::string>(battlefield);
    Display_Message<std::string>("\n");

    Display_Message<std::string>("season : ");
    Display_Message<std::string>(season);
    Display_Message<std::string>("\n");

    Display_Hand(players_turn[current_player]);
    Display_Message<std::string>("@");
    Display_Message<std::string>(players_turn[current_player]->Get_Name());
    Display_Message<std::string>(" : ");
}

// Show conquered provinces
void UI::Display_Acquired_Provinces(std::shared_ptr<Player> &player)
{
    Display_Message<std::string>("Provinces occupied by ");
    Display_Message<std::string>(player->Get_Name() + " : ");
    bool is_first = true;
    for (const auto province : player->Get_Acquired_Provinces())
    {
        if (!is_first)
            Display_Message<std::string>(" - ");
        Display_Message<std::string>(province);
        is_first = false;
    }
    Display_Message<std::string>("\n");
}

// get the line and converting uppercase letters to lowercase
std::string UI::Get_Line_Tolower()
{
    std::string line;
    std::getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    return line;
}

// get the line and converting lowercase letters to uppercase
std::string UI::Get_Line_Toupper()
{
    std::string line;
    std::getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    return line;
}