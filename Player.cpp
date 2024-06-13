#include "Player.hpp"
#include "UI.hpp"

Player::Player(const std::string &name, const int &age, const std::string &color) : name(name), age(age), color(color), acquired_provinces(0){};

Player::~Player()
{
    for (Card *card : hand)
    {
        delete card;
    }
}

void Player::Add_Card(Card *const card)
{
    hand.push_back(card);
}

bool Player::Play_Card(const std::string &cardType)
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        if ((*it)->Get_Type() == cardType)
        {
            hand.erase(it);
            return true;
        }
    }
    return false;
}

std::string Player::Get_Name() const
{
    return name;
}

int Player::Get_Age() const
{
    return age;
}

std::string Player::Get_Color() const
{
    return color;
}

int Player::Get_Acquired_Provinces() const
{
    return acquired_provinces;
}

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