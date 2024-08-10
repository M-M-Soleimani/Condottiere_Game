#include "Vexillary.hpp"

// Constructor to create an instance of the Vexillary
Vexillary::Vexillary() : Card("vexillary", 0, "When a player plays a flag, that war is immediately over and that round of the game goes to the stage of determining the winner and then reviving.\n", Card::Color::Purple)
{
    this->Set_Score(0);
}

// To handle the absence of errors due to overload and override
std::string Vexillary::perform_Action() 
{
    return this->Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Vexillary::perform_Action(std::shared_ptr<Player> & player) 
{
    return this->Get_Type();
}

// Override and overloaded function to apply card abilities to the game
std::string Vexillary::perform_Action(std::vector<std::shared_ptr<Player>> & players_turn) 
{
    players_turn.clear();
    return this->Get_Type();
}