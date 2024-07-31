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

// Distractor of Deck class
Deck::~Deck()
{
    for (Card *card : cards)
    {
        delete card;
    }
}

// Add card to cards vector
void Deck::Add_Card(Card *card)
{
    cards.push_back(card);
}

// Draw card
Card *Deck::Draw_Card()
{
    if (cards.empty())
        return nullptr;

    Card *drawn_card = cards.back();
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
    Card *temp = nullptr;
    for (size_t i = 0; i < 10; ++i)
    {
        temp = new YellowCard("1", 1);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("2", 2);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("3", 3);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("4", 4);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("5", 5);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("6", 6);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 8; ++i)
    {
        temp = new YellowCard("10", 10);
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);


    for (size_t i = 0; i < 16; ++i)
    {
        temp = new Matarsak;
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 3; ++i)
    {
        temp = new Bahar;
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 3; ++i)
    {
        temp = new Zemestan;
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    for (size_t i = 0; i < 3; ++i)
    {
        temp = new Shah_dokht;
        cards.push_back(temp);
    }
    playing_cards_list.push_back(temp);

    Shuffle(); // Shuffle the deck of cards to normalize the order of the cards
}

// Return playing cards list
std::vector<Card*> Deck::Get_Playing_Cards_List()
{
    return playing_cards_list;
}