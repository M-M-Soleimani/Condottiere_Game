#include "Card.hpp"
#include "YellowCard.hpp"

// Constructor to create an instance of the yellow card class with parameter
YellowCard::YellowCard(std::string type, int value)
    : Card(type, value, "Soldier cards make up your army and have a yellow border\nA color and a number are specified. Any soldier card that is played\nIncreases the strength of the player's army by the number on the card.\nAt The end of each battle is if the sum of the numbers of your cards is greater than the others\nYou get the province.\n", Color::Yellow) {}

// Override and overloaded function to apply card abilities to the game ; in this case, no special feature is applied 
std::string YellowCard::perform_Action()
{
    return Get_Type() + " played";
}

// To handle the absence of errors due to overload and override
std::string YellowCard::perform_Action(Player &player) {}

// To handle the absence of errors due to overload and override
std::string YellowCard::perform_Action(std::vector<Card *> &allCards) {}