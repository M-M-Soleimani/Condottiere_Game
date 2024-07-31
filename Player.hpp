#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(const std::string &, const int &, const std::string &); // constructor to initialize and create an instance of the player class
    ~Player();                                                     // Destructor for player class
    void Add_Card(Card *const);                                    // Adding cards to the player's hand
    bool Play_Card(const std::string &);                           // The function of playing cards by the player
    std::string Get_Name() const;                                  // Return name of player
    int Get_Age() const;                                           // Return age of player
    std::string Get_Color() const;                                 // Return color of player
    void Set_hand(const std::vector<Card *> &);                    // set the hand of player
    std::vector<Card *> &Get_hand();                               // Return hand of player
    void Set_played_crads(const std::vector<Card *> &);            // set the played cards
    std::vector<Card *> &Get_played_crads();                       // Return cards that player played
    int Get_Acquired_Provinces() const;                            // Return Acquired Provinces of player
    void display_hand() const;                                     // display hand of player

private:
    std::string name;
    int age;
    std::string color;
    std::vector<Card *> hand;
    std::vector<Card *> played_crads;
    int acquired_provinces;
};

#endif