#ifndef SHAH_DOKHT_HPP
#define SHAH_DOKHT_HPP
#include "Card.hpp"

class Shah_dokht : public Card
{
public:
    Shah_dokht();                                                                      // Constructor to create an instance of class Shah_dokht
    virtual std::string perform_Action() override;                                     // Override and overloaded function to apply card abilities to the game ; in this case, no special feature is applied
    virtual std::string perform_Action(std::shared_ptr<Player> &) override;            // To handle the absence of errors due to overload and override
    virtual std::string perform_Action(std::vector<std::shared_ptr<Card>> &) override; // To handle the absence of errors due to overload and override
};

#endif