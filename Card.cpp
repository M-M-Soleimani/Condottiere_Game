#include "Card.hpp"

Card::Card(std::string type, int value, std::string description, Color color) : type(type), description(description), color(color)
{
    (value > 0) ? this->value = value : this->value = 0;
    score = value;
}

std::string Card::Get_Type() const
{
    return type;
}

int Card::Get_Value() const
{
    return value;
}

int Card::Get_Score() const
{
    return score;
}

void Card::Set_Score(int score)
{
    if (score > 0)
        this-> score = score;
}

std::string Card::Get_Description() const
{
    return description;
}

Card::Color Card::Get_Color() const
{
    return color;
}