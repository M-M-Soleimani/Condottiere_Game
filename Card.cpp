#include "Card.hpp"

// Class constructor for parameter initialization
Card::Card(std::string type, int value, std::string description, Color color) : type(type), description(description), color(color)
{
    (value > 0) ? this->value = value : this->value = 0;
    score = value;
}

// Return card type
std::string Card::Get_Type() const
{
    return type;
}

// Return card value
int Card::Get_Value() const
{
    return value;
}

// Return card score
int Card::Get_Score() const
{
    return score;
}

// Set the value of the score with the input parameter
void Card::Set_Score(int score)
{
    if (score > 0)
        this->score = score;
}

// Return card description
std::string Card::Get_Description() const
{
    return description;
}

// Return card color
Card::Color Card::Get_Color() const
{
    return color;
}