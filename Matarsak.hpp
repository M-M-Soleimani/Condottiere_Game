#ifndef MATARSAK_HPP
#define MATARSAK_HPP
#include "Card.hpp"
#include <memory>

class Matarsak : public Card
{
public:
    Matarsak();                                                                        // constructor to initialize and create an instance of the Matarsak class
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;            // Override and overloaded function to apply card abilities to the game ; in this cas , Returning the card to the user
    virtual std::string perform_Action() override;                                     // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Card>> &) override; // To handle the absence of errors due to overload and override
};

#endif