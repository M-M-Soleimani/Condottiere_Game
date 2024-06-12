#include "Card.hpp"
#include "Shah_dokht.hpp"

// Constructor to create an instance of class Shah_dokht
Shah_dokht::Shah_dokht() : Card("shah_dokht", 10, "Each shah_dokht card increases the strength of the player's army by 10 units.\ntip:\nRisfid, matarsak, zemestan, bahar and tabl_zan do not affect the shah_dokht.\n", Color::Purple) {}

// An overridden function for special card action
bool Shah_dokht::perform_Action(std::vector<Card *> &)
{
    return true;
}