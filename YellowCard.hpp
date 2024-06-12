#ifndef YELLOWCARD_HPP
#define YELLOWCARD_HPP

#include "Card.hpp"

class YellowCard : public Card
{
public:
    YellowCard(std::string, int);   // Constructor to create an instance of the yellow card class
    virtual bool perform_Action(std::vector<Card *> &) override;    // An overridden class for special card functions
};

#endif