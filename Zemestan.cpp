#include "Zemestan.hpp"

// Constructor to create an instance of class Zemestan
Zemestan::Zemestan() : Card::Card("zemestan", 0, "zemestan: When the zemestan card is played, the number of soldier cards (yellow) is all\nPlayers equals 1. The effect of zemestan lasts as long as it lasts.\nFor example, if a player has 1 soldier, 4 soldiers, 10 and 1 in his army\nSoldier has 2. After the zemestan is played, the total number of his army is\n16th place will be equal to 3.\n", Color::Purple) {}

// To reduce the score of each card to 1
std::string Zemestan::perform_Action(std::vector<std::shared_ptr<Card>> &cards)
{
    for (auto &card : cards)
    {
        card->Set_Score(1);
    }
    return Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Zemestan::perform_Action()
{
    return NULL;
}

// To handle the absence of errors due to overload and override
std::string Zemestan::perform_Action(std::shared_ptr<Player> &player)
{
    return NULL;
}