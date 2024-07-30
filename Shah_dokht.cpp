#include "Card.hpp"
#include "Shah_dokht.hpp"

// Constructor to create an instance of class Shah_dokht
Shah_dokht::Shah_dokht() : Card("shah_dokht", 10, "Each shah_dokht card increases the strength of the player's army by 10 units.\ntip:\nRisfid, matarsak, zemestan, bahar and tabl_zan do not affect the shah_dokht.\n", Color::Purple) {}

// Override and overloaded function to apply card abilities to the game ; in this case, no special feature is applied 
std::string Shah_dokht::perform_Action()
{
    return Get_Type() + " played";
}

// To handle the absence of errors due to overload and override
std::string Shah_dokht::perform_Action(Player & player) {}

// To handle the absence of errors due to overload and override
std::string Shah_dokht::perform_Action(std::vector<Card *> & player_cards) {}