#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "Card.hpp"

class Deck
{
public:
    Deck();                                                         // Constructor to create an instance of class Deck
    ~Deck();                                                        // Default distractor of Deck class
    void Add_Card(std::shared_ptr<Card>);                           // Add card to cards vector
    std::shared_ptr<Card> Draw_Card();                              // Draw card
    void Shuffle();                                                 // Shuffle vector of card
    void Deck_Initializer();                                        // Initialize the Deck
    std::vector<std::shared_ptr<Card>> Get_Playing_Cards_List();    // Return playing cards list
    std::shared_ptr<Card> Get_And_Delete_Card(const std::string &); // Find the card and return it and remove it from the card deck

private:
    std::vector<std::shared_ptr<Card>> cards;
    std::vector<std::shared_ptr<Card>> playing_cards_list;
};

#endif