#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "Card.hpp"

class Deck
{
public:
    Deck();
    ~Deck();
    void Add_Card(Card *);
    Card* Draw_Card();
    void Shuffle();
    
private:
    std::vector<Card *> cards;
};

#endif