#ifndef WHITE_SEALS_HPP
#define WHITE_SEALS_HPP

#include "Card.hpp"

class White_Seals : public Card
{
public:
    White_Seals();                                                                       // Constructor to create an instance of the White_Seals class
    virtual std::string perform_Action() override;                                       // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;              // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Player>> &) override; // Override and overloaded function to apply card abilities to the game
};

#endif