#include "Heroine.hpp"

// Constructor to create an instance of the Heroine class
Heroine::Heroine() : Card("heroine", 1, "heroine :\nIt has two features :\n1. Each heroine card increases the strength of the player's army by 1 unit.\n2. At the end of the war, the player who has played the most heroine cards determines the location of the next battle. If the players are equal in the number of heroine cards, the same winning player determines the location of the next battle.", Card::Color::Purple)
{
    this->Set_Score(1);
}

// Override and overloaded function to apply card abilities to the game
std::string Heroine::perform_Action()
{
    return this->Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Heroine::perform_Action(std::shared_ptr<Player> &)
{
    return this->Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Heroine::perform_Action(std::vector<std::shared_ptr<Player>> &)
{
    return this->Get_Type();
}