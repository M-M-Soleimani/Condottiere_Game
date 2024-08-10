#include "Player.hpp"
#include "UI.hpp"

// Class constructor for parameter initialization
Player::Player(const std::string &name, const int &age, const std::string &color) : name(name), age(age), color(color), acquired_provinces(0) {};

// class destructor to clear the card stack to prevent memory leaks
Player::~Player() {}

// Add card to player hand
void Player::Add_Card(std::shared_ptr<Card> card)
{
    hand.push_back(card);
}

// Play card with player
std::shared_ptr<Card> Player::Play_Card(const std::string &cardType)
{
    std::shared_ptr<Card> temp = nullptr;
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        if ((*it)->Get_Type() == cardType)
        {
            played_crads.push_back(*it);
            hand.erase(it);
            break;
        }
    }
    return temp;
}

// Return name of player
std::string Player::Get_Name() const
{
    return name;
}

// Return age of player
int Player::Get_Age() const
{
    return age;
}

// Return color of player
std::string Player::Get_Color() const
{
    return color;
}

// Return Acquired Provinces of player
std::vector<std::string> Player::Get_Acquired_Provinces() const
{
    return acquired_provinces;
}

void Player::Add_Acquired_Provinces(const std::string &new_province)
{
    acquired_provinces.push_back(new_province);
}

// Set the hand of player
void Player::Set_hand(const std::vector<std::shared_ptr<Card>> &cards)
{
    hand = cards;
}

// Return hand of player
std::vector<std::shared_ptr<Card>> Player::Get_hand()
{
    return hand;
}

// Set the played cards
void Player::Set_played_crads(const std::vector<std::shared_ptr<Card>> &cards)
{
    played_crads = cards;
}

// Return cards that player played
std::vector<std::shared_ptr<Card>> &Player::Get_played_crads()
{
    return played_crads;
}

// Returns whether the player has a war badge or not
bool Player::Get_War_Badge()
{
    return war_badge;
}

// Set player have war badge or not
void Player::Set_War_Badge(const bool &war_badge)
{
    this->war_badge = war_badge;
}

// Return card score
int Player::Get_Score() const
{
    return score;
}

// Set the value of the score with the input parameter
void Player::Set_Score(const int &score)
{
    this->score = score;
}

// Clear cards in hand of player
void Player::burning_Hand(std::vector<std::shared_ptr<Card>> &played_cards)
{
    for (auto card : hand)
    {
        played_cards.push_back(card);
    }
    hand.clear();
}

// Clear played card of player
void Player::burning_Played_Cards()
{
    played_crads.clear();
}

// Returns whether the player has a peace sign or not
bool Player::Get_Peace_Sign()
{
    return peace_sign;
}

// Set player have peace sign or not
void Player::Set_Peace_Sign(const bool &peace_sign)
{
    this->peace_sign = peace_sign;
}