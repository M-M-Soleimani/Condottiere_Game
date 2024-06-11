#ifndef YELLOWCARD_HPP
#define YELLOWCARD_HPP

#include "Card.hpp"

class YellowCard : public Card
{
public:
    YellowCard(std::string, int, std::string);
    bool perform_Action(std::vector<Card *> &) override;
};

#endif