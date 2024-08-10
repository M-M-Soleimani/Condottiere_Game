#ifndef HEROINE_HPP
#define HEROINE_HPP

#include "Card.hpp"
#include <string>
#include "Player.hpp"

class Heroine : public Card
{
public:
    Heroine();                                                          // Constructor to create an instance of the yellow card class with parameter
    std::string perform_Action();                                       // Override and overloaded function to apply card abilities to the game
    std::string perform_Action(std::shared_ptr<Player> &);              // To handle the absence of errors due to overload and override
    std::string perform_Action(std::vector<std::shared_ptr<Player>> &); // To handle the absence of errors due to overload and override
};

#endif