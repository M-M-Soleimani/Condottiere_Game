#include "Elder.hpp"

// Constructor to create an instance of the class Elder
Elder::Elder() : Card("elder", 0, "When a player plays Whitebeard, the highest number played in the army line finds all players and any player who has that card burns it!Then the player who played Whitebeard takes the peace token and places it in an empty province. This token remains unchanged until the next time Whitebeard is played.Features of the Peace Sign: You cannot start a war in a province that has a peace sign", Card::Color::Purple)
{
    this->Set_Score(0);
}

// To handle the absence of errors due to overload and override
std::string Elder::perform_Action()
{
    return this->Get_Type();
}

// Override and overloaded function to apply card abilities to the game
std::string Elder::perform_Action(std::shared_ptr<Player> &)
{
    return this->Get_Type();
}

// To handle the absence of errors due to overload and override
std::string Elder::perform_Action(std::vector<std::shared_ptr<Player>> &players)
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

    // the highest number played in the army line finds all players and any player who has that card burns it
    int index = 0;
    for (auto player : players)
    {
        index = 0;
        std::vector<std::shared_ptr<Card>> &played_cards = player->Get_played_crads();
        std::vector<int> max_played_cards_indexes;
        for (auto card : played_cards)
        {
            if (card->Get_Score() == max_score)
            {
                max_played_cards_indexes.push_back(index);
            }
            ++index;
        }
        for(auto index :max_played_cards_indexes)
        {
            played_cards.erase(played_cards.begin()+index);
        }
    }
    return this->Get_Type();
}
