#include "Player.hpp"
#include "UI.hpp"

// Class constructor for parameter initialization
Player::Player(const std::string &name, const int &age, const std::string &color) : name(name), age(age), color(color), acquired_provinces(0) {};

// class destructor to clear the card stack to prevent memory leaks
Player::~Player()
{
    for (Card *card : hand)
    {
        delete card;
    }
}

// Add card to player hand
void Player::Add_Card(Card *const card)
{
    hand.push_back(card);
}

// Play card with player
bool Player::Play_Card(const std::string &cardType)
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        if ((*it)->Get_Type() == cardType)
        {
            played_crads.push_back(*it);
            hand.erase(it);
            return true;
        }
    }
    return false;
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
int Player::Get_Acquired_Provinces() const
{
    return acquired_provinces;
}

// Set the hand of player
void Player::Set_hand(const std::vector<Card *> &cards)
{
    hand = cards;
}

// Return hand of player
std::vector<Card *> &Player::Get_hand()
{
    return hand;
}

// Set the played cards
void Player::Set_played_crads(const std::vector<Card *> &cards)
{
    played_crads = cards;
}

// Return cards that player played
std::vector<Card *> &Player::Get_played_crads()
{
    return played_crads;
}

// Display hand of player
void Player::display_hand() const
{
    UI ui;
    ui.Display_Message(this->Get_Name());
    ui.Display_Message("'s hand : ");
    bool is_first = true;
    for (Card const *const card : hand)
    {
        if (!is_first)
            ui.Display_Message(" - ");
        ui.Display_Message(card->Get_Type());
        is_first = false;
    }
}