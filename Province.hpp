#ifndef PROVINCE_HPP
#define PROVINCE_HPP
#include "Player.hpp"
#include <string>
#include <set>

class Province
{
public:
    Province();                                         // Default constructor for the province class
    Province(std::string);                              // Constructor for naming and initializing the province
    ~Province();                                        // Default destructor for province class
    void Set_Owner(Player *);                           // Set the owner of the province
    void Set_Adjacent_Provinces(const std::set<int> &); // Set the adjacent of the provinces
    Player *Get_Owner();                                // Returning the owner of the province
    std::set<int> Get_Adjacent_Provinces();             // Returning the neighbors of the province

private:
    std::string name;                 // province name
    Player *owner;                    // The owner of the province
    std::set<int> adjacent_provinces; // Adjacent provinces
};

#endif