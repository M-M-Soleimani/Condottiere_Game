#include "Province.hpp"
#include "Player.hpp"
#include <string>
#include <set>

// Default constructor for the province class
Province::Province() = default;

// Constructor for naming and initializing the province
Province::Province(std::string name) : name(name), owner(nullptr) {}

// Default destructor for province class
Province::~Province() = default;

// Set the owner of the province
void Province::Set_Owner(std::shared_ptr<Player> player)
{
    owner = player;
}

// Set the adjacent of the provinces
void Province::Set_Adjacent_Provinces(const std::set<int> &adjacent_provinces)
{
    this->adjacent_provinces = adjacent_provinces;
}

// Returning the owner of the province
std::shared_ptr<Player> Province::Get_Owner()
{
    return owner;
}

// Returning the neighbors of the province
std::set<int> Province::Get_Adjacent_Provinces()
{
    return adjacent_provinces;
}

std::string Province::Get_Name()
{
    return name;
}

// Returns whether the peace sign has been placed in this province or not
bool Player::Get_Peace_Sign()
{
    return peace_sign;
}

// Set province have peace sign or not
void Player::Set_Peace_Sign(const bool &peace_sign)
{
    this->peace_sign = peace_sign;
}