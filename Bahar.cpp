#include "Bahar.hpp"
#include "Player.hpp"

// Constructor to create an instance of class Bahar
Bahar::Bahar() : Card::Card("bahar", 0, "Spring: When the spring card is played, first check that the highest card is played\nHow much is on the table? Then until the spring, any player who\nFrom that card in his army line, add 3 units to his army number\nwill be For example, if the highest card played on the table is 5, any player\nIf he has 5, as long as it is spring, his army number will be added to 3.\n", Color::Purple) {}

// Override and overloaded function to apply card abilities to the game ; in this case, 3 points are added to the card or cards with the highest score
std::string Bahar::perform_Action(std::vector<std::shared_ptr<Player>> &players)
{
    // Find the card with the highest score
    int max_score = 0;
    for (auto player : players)
    {
        for (auto card : player->Get_played_crads())
        {
            if (card->Get_Score() > max_score)
            {
                max_score = card->Get_Score();
            }
        }
    }
    // Increase of 3 points for each card
    for (auto player : players)
    {
        for (auto card : player->Get_played_crads())
        {
            if (card->Get_Score() == max_score)
            {
                card->Set_Score(card->Get_Score() + 3);
            }
        }
    }

    return Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Bahar::perform_Action()
{
    return NULL;
}

// To handle the absence of errors due to overload and override
std::string Bahar::perform_Action(std::shared_ptr<Player> &player)
{
    return NULL;
}