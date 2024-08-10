#include "White_Seals.hpp"
#include "Player.hpp"

// Constructor to create an instance of the White_Seals class
White_Seals::White_Seals() : Card("white_seals", 0, "nothing", Card::Color::Purple)
{
    this->Set_Score(0);
}

// To handle the absence of errors due to overload and override
std::string White_Seals::perform_Action()
{
    return this->Get_Type();
} 

// To handle the absence of errors due to overload and override
std::string White_Seals::perform_Action(std::shared_ptr<Player> &player)
{
    return this->Get_Type();
}             

// Override and overloaded function to apply card abilities to the game
std::string White_Seals::perform_Action(std::vector<std::shared_ptr<Player>> & players)
{
    for(auto player : players)
    {
        player->burning_Played_Cards();
    }
}