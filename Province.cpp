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
void Province::Set_Owner(Player *player)
{
    owner = player;
}

// Set the adjacent of the provinces
void Province::Set_Adjacent_Provinces(const std::set<int> &adjacent_provinces)
{
    this->adjacent_provinces = adjacent_provinces;
}

// Returning the owner of the province
Player *Province::Get_Owner()
{
    return owner;
}

// Returning the neighbors of the province
std::set<int> Province::Get_Adjacent_Provinces()
{
    return adjacent_provinces;
}