#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(const std::string &, const int &, const std::string &);     // constructor to initialize and create an instance of the player class
    ~Player();                                                         // Destructor for player class
    void Add_Card(std::shared_ptr<Card>);                              // Adding cards to the player's hand
    std::shared_ptr<Card> Play_Card(const std::string &);              // The function of playing cards by the player
    std::string Get_Name() const;                                      // Return name of player
    int Get_Age() const;                                               // Return age of player
    std::string Get_Color() const;                                     // Return color of player
    void Set_hand(const std::vector<std::shared_ptr<Card>> &);         // set the hand of player
    std::vector<std::shared_ptr<Card>> Get_hand();                     // Return hand of player
    void Set_played_crads(const std::vector<std::shared_ptr<Card>> &); // set the played cards
    std::vector<std::shared_ptr<Card>> &Get_played_crads();            // Return cards that player played
    std::vector<std::string> Get_Acquired_Provinces() const;           // Return Acquired Provinces of player
    void Add_Acquired_Provinces(const std::string &);                  // Adding the name of the conquered province to the conquered provinces vector
    bool Get_War_Badge();                                              // Returns whether the player has a war badge or not
    void Set_War_Badge(const bool &);                                  // Set player have war badge or not
    int Get_Score() const;                                             // Return card score
    void Set_Score(const int &);                                       // Set the value of the score with the input parameter
    void burning_Hand(std::vector<std::shared_ptr<Card>> &);           // Clear cards in hand of player
    void burning_Played_Cards();                                       // Clear played card of player

private:
    std::string name;
    int age;
    std::string color;
    std::vector<std::shared_ptr<Card>> hand;
    std::vector<std::shared_ptr<Card>> played_crads;
    std::vector<std::string> acquired_provinces;
    bool war_badge = false;
    int score = 0;
};

#endif