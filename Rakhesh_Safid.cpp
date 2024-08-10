#include "Rakhesh_Safid.hpp"

// Constructor to create an instance of the White_Seals class
Rakhesh_Safid::Rakhesh_Safid() : Card("rakhesh_safid" , 0 , "nothing" , Card::Color::Purple)
{
    this->Set_Score(0);
}

// To handle the absence of errors due to overload and override
std::string Rakhesh_Safid::perform_Action()
{
    return this->Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Rakhesh_Safid::perform_Action(std::shared_ptr<Player> &player)
{
    return this->Get_Type();
}

// Override and overloaded function to apply card abilities to the game
std::string Rakhesh_Safid::perform_Action(std::vector<std::shared_ptr<Player>> &players_turn)
{
    players_turn.clear();
    return this->Get_Type();
} 
