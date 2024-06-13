#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(const std::string &, const int &, const std::string &);
    ~Player();
    void Add_Card(Card *const);
    bool Play_Card(const std::string &);
    std::string Get_Name() const;
    int Get_Age() const;
    std::string Get_Color() const;
    int Get_Acquired_Provinces() const;
    void display_hand() const;

private:
    std::string name;
    int age;
    std::string color;
    std::vector<Card *> hand;
    int acquired_provinces;
};

#endif