#ifndef TABL_ZAN_HPP
#define TABL_ZAN_HPP
#include "Card.hpp"

class Tabl_zan : public Card
{
public:
    Tabl_zan();                                                         // Constructor to create an instance of class Tabl_zan
    virtual std::string perform_Action() override;                      // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(Player &) override;              // An overridden and overloaded function to duplicate the value of all cards played by the user
    virtual std::string perform_Action(std::vector<Card *> &) override; // To handle the absence of errors due to overload and override
};

#endif