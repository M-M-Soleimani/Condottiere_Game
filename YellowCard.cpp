#include "Card.hpp"
#include "YellowCard.hpp"

YellowCard::YellowCard(std::string type, int value, std::string description) : Card(type, value, description, Color::Yellow) {}

bool YellowCard::perform_Action(std::vector<Card *> &allCards) 
{
    return true;
}