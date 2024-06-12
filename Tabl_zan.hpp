#ifndef TABL_ZAN_HPP
#define TABL_ZAN_HPP
#include "Card.hpp"

class Tabl_zan : public Card
{
public:
    Tabl_zan(); // Constructor to create an instance of class Tabl_zan
    virtual bool perform_Action(std::vector<Card *> &) override;    //  An overridden function to double the value of all cards played by the user
};

#endif