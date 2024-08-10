#include "Card.hpp"

#ifndef VEXILLARY_HPP
#define VEXILLARY_HPP

class Vexillary : public Card
{
public:
    Vexillary();                                                                         // Constructor to create an instance of the Vexillary
    virtual std::string perform_Action() override;                                       // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;              // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Player>> &) override; // Override and overloaded function to apply card abilities to the game
};

#endif