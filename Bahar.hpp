#ifndef BAHAR_HPP
#define BAHAR_HPP
#include "Card.hpp"

class Bahar : public Card
{
public:
    Bahar();                                                                           // Constructor to create an instance of class Bahar
    virtual std::string perform_Action(std::vector<std::shared_ptr<Player>> &) override; // Override and overloaded function to apply card abilities to the game ; in this case, 3 points are added to the card or cards with the highest score
    virtual std::string perform_Action() override;                                     // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;            // To handle the absence of errors due to overload and override
};

#endif