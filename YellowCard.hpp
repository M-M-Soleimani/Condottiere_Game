#ifndef YELLOWCARD_HPP
#define YELLOWCARD_HPP

#include "Card.hpp"

class YellowCard : public Card
{
public:
    YellowCard(std::string, int);                                                      // Constructor to create an instance of the yellow card class with parameter
    virtual std::string perform_Action() override;                                     // Override and overloaded function to apply card abilities to the game
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;            // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Card>> &) override; // To handle the absence of errors due to overload and override
};

#endif