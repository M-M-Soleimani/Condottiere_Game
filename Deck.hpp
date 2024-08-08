#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "Card.hpp"

class Deck
{
public:
    Deck();                                                      // Constructor to create an instance of class Deck
    ~Deck();                                                     // Distractor of Deck class
    void Add_Card(std::shared_ptr<Card>);                        // Add card to cards vector
    std::shared_ptr<Card> Draw_Card();                           // Draw card
    void Shuffle();                                              // Shuffle vector of card
    void Deck_Initializer();                                     // Initialize the Deck

private:
    std::vector<std::shared_ptr<Card>> cards;
};

#endif