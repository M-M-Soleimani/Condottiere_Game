#include "Card.hpp"
#include "YellowCard.hpp"

// Constructor to create an instance of the yellow card class
YellowCard::YellowCard(std::string type, int value) 
: Card(type, value, "Soldier cards make up your army and have a yellow border\nA color and a number are specified. Any soldier card that is played\nIncreases the strength of the player's army by the number on the card.\nAt The end of each battle is if the sum of the numbers of your cards is greater than the others\nYou get the province.\n", Color::Yellow) {}

// An overridden class for special card functions
bool YellowCard::perform_Action(std::vector<Card *> &allCards) 
{
    return true;
}

