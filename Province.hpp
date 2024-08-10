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
    void Set_Owner(std::shared_ptr<Player>);            // Set the owner of the province
    void Set_Adjacent_Provinces(const std::set<int> &); // Set the adjacent of the provinces
    std::shared_ptr<Player> Get_Owner();                // Returning the owner of the province
    std::set<int> Get_Adjacent_Provinces();             // Returning the neighbors of the province
    std::string Get_Name();                             // Returning the name of the province
    bool Get_Peace_Sign();                              // Returns whether the peace sign has been placed in this province or not
    void Set_Peace_Sign(const bool &);                  // Set province have peace sign or not

private:
    std::string name;                 // province name
    std::shared_ptr<Player> owner;    // The owner of the province
    std::set<int> adjacent_provinces; // Adjacent provinces
    bool peace_sign = false;
};

#endif