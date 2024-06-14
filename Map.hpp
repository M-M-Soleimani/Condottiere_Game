#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include "Player.hpp"
#include <map>
#include <set>
#include "Province.hpp"

class Map
{
public:
    // enum class to convert names to numeric identifiers
    enum class province
    {
        BELLA,
        CALINE,
        ENNA,
        ATELA,
        PLADACI,
        BORGE,
        DIMASE,
        MORINA,
        OLIVIA,
        ROLLO,
        TALMONE,
        ARMENTO,
        LIA,
        ELINA
    };
    Map();                                                           // The constructor of the Map class with default values
    ~Map();                                                          // Default distractor
    void Add_Province(const int &, const Province &);                // Add the province to the map
    void Set_Adjacent_Provinces(const int &, const std::set<int> &); // Set neighboring provinces for a province
    void Set_Province_Owner(const int &, Player *);                  // Register the winner as the owner of the province
    std::map<Player *, std::set<int>> Get_Player_provinces();        // returning map that connects players to captured provinces
    std::map<int, Province> Get_Provinces();                         // Returning a map that connects the name (with numerical identifier) ​​to the provinces

private:
    std::map<int, Province> provinces;                  // To map players to a captured province
    std::map<Player *, std::set<int>> player_provinces; // To map the name (numerical identifier) ​​to the provinces
};

#endif