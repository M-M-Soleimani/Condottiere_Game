#ifndef ELDER_HPP
#define ELDER_HPP

#include "Card.hpp"
#include "Player.hpp"
#include <vector>

class Elder : public Card
{
public:
    Elder();                                                                             // Constructor to create an instance of the class Elder
    virtual std::string perform_Action() override;                                       // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;              // Override and overloaded function to apply card abilities to the game
    virtual std::string perform_Action(std::vector<std::shared_ptr<Player>> &) override; // To handle the absence of errors due to overload and override
};

#endif