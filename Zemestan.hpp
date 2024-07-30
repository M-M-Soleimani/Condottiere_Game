#ifndef ZEMESTAN_HPP
#define ZEMESTAN_HPP
#include "Card.hpp"

class Zemestan : public Card
{
public:
    Zemestan();                                                         // Constructor to create an instance of class Zemestan
    virtual std::string perform_Action(std::vector<Card *> &) override; // Override and overloaded function to apply card abilities to the game ; in this case , reduce the score of each card to 1
    virtual std::string perform_Action() override;                      // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(Player &) override;              // To handle the absence of errors due to overload and override
};

#endif