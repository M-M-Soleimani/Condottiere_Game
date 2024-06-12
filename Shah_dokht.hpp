#ifndef SHAH_DOKHT_HPP
#define SHAH_DOKHT_HPP
#include "Card.hpp"

class Shah_dokht : public Card
{
public:
    Shah_dokht();   // Constructor to create an instance of class Shah_dokht
    virtual bool perform_Action(std::vector<Card *> &) override;    // An overridden function for special card action
};

#endif