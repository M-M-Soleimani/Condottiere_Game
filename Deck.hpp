#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "Card.hpp"

class Deck
{
public:
    Deck();                                       // Constructor to create an instance of class Deck
    ~Deck();                                      // Distractor of Deck class
    void Add_Card(Card *);                        // Add card to cards vector
    Card *Draw_Card();                            // Draw card
    void Shuffle();                               // Shuffle vector of card
    void Deck_Initializer();                      // Initialize the Deck
    std::vector<Card *> Get_Playing_Cards_List(); // Return playing cards list

private:
    std::vector<Card *> cards;
    std::vector<Card *> playing_cards_list;
};

#endif