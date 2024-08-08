#include "Deck.hpp"
#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Bahar.hpp"
#include "Zemestan.hpp"
#include "YellowCard.hpp"
#include "Tabl_zan.hpp"
#include "Shah_dokht.hpp"
#include "Matarsak.hpp"

// Constructor to create an instance of class Deck
Deck::Deck()
{
    Deck_Initializer();
}

// Default distractor of Deck class
Deck::~Deck() = default;

// Add card to cards vector
void Deck::Add_Card(std::shared_ptr<Card>card)
{
    cards.push_back(card);
}

// Draw card
std::shared_ptr<Card>Deck::Draw_Card()
{
    if (cards.empty())
        return nullptr;

    std::shared_ptr<Card>drawn_card = cards.back();
    cards.pop_back();
    return drawn_card;
}

// Shuffle vector of card
void Deck::Shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

// Initialize the Deck 
void Deck::Deck_Initializer()
{
    // Creating a deck of cards as a vector of pointers that point to the heap space
    std::shared_ptr<Card>temp = nullptr;
    for (size_t i = 0; i < 10; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("1" , 1));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("2" , 2));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("3" , 3));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("4" , 4));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("5" , 5));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("6" , 6));
    }

    for (size_t i = 0; i < 8; ++i)
    {
        cards.push_back(std::make_shared <YellowCard> ("10" , 10));
    }


    for (size_t i = 0; i < 16; ++i)
    {
        cards.push_back(std::make_shared <Matarsak>());
    }

    for (size_t i = 0; i < 3; ++i)
    {
        cards.push_back(std::make_shared <Bahar>());
    }

    for (size_t i = 0; i < 3; ++i)
    {
        cards.push_back(std::make_shared <Zemestan>());
    }

    for (size_t i = 0; i < 3; ++i)
    {
        cards.push_back(std::make_shared <Shah_dokht>());
    }

    for (size_t i = 0; i < 6; ++i)
    {
        cards.push_back(std::make_shared <Tabl_zan>());
    }

    Shuffle(); // Shuffle the deck of cards to normalize the order of the cards
}