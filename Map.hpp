#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include "Player.hpp"
#include <map>
#include <set>
#include "Province.hpp"
#include <memory>

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
        OLIVADI,
        ROLLO,
        TALMONE,
        ARMENTO,
        LIA,
        ELINA,
        MATIN,
    };
    Map();                                                                   // The constructor of the Map class with default values
    ~Map();                                                                  // Default distractor
    void Add_Province(const int &, const Province &);                        // Add the province to the map
    void Set_Adjacent_Provinces(const int &, const std::set<int> &);         // Set neighboring provinces for a province
    void Set_Province_Owner(const std::string &, std::shared_ptr<Player>);   // Register the winner as the owner of the province
    std::map<std::shared_ptr<Player>, std::set<int>> Get_Player_provinces(); // returning map that connects players to captured provinces
    std::map<int, Province> Get_Provinces();                                 // Returning a map that connects the name (with numerical identifier) ​​to the provinces
    void Map_Initializer();                                                  // Add provinces and adjust neighboring provinces
    void Set_Peace_Sign(const std::string &, const bool &);                  // Set province have peace sign or not
    bool Get_Peace_Sign(const std::string &);                                // Returns whether the peace sign has been placed in this province or not

private:
    std::map<int, Province> provinces;                                 // To map players to a captured province
    std::map<std::shared_ptr<Player>, std::set<int>> player_provinces; // To map the name (numerical identifier) ​​to the provinces
};

#endif