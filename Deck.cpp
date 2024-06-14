#include "Deck.hpp"
#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {}

Deck::~Deck()
{
    for (Card *card : cards)
    {
        delete card;
    }
}

void Deck::Add_Card(Card *card)
{
    cards.push_back(card);
}

Card *Deck::Draw_Card()
{
    if (cards.empty())
        return nullptr;

    Card *drawn_card = cards.back();
    cards.pop_back();
    return drawn_card;
}

void Deck::Shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}