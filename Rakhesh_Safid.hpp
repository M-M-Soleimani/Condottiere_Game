#ifndef RAKHESH_SAFID_HPP
#define RAKHESH_SAFID_HPP

#include "Card.hpp"

class Rakhesh_Safid : public Card
{
public:
    Rakhesh_Safid();                                                                     // Constructor to create an instance of the White_Seals class
    virtual std::string perform_Action() override;                                       // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;              // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Player>> &) override; // Override and overloaded function to apply card abilities to the game
};

#endif