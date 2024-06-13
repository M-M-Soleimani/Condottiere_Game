#ifndef MATARSAK_HPP
#define MATARSAK_HPP
#include "Card.hpp"

class Matarsak : public Card
{
public:
    Matarsak(); // // A constructor to initialize and create an instance of the Matarsak class
    virtual bool perform_Action(std::vector<Card *> &) override;    // Implementation of the function of returning the card to the user
};

#endif