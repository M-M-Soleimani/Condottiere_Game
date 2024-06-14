#include "Map.hpp"

// The constructor of the Map class with default values
Map::Map() = default;

// Default distractor
Map::~Map() = default;

// Add the province to the map
void Map::Add_Province(const int &origin_province_name, const Province &province)
{
    provinces[origin_province_name] = province;
}

// Set neighboring provinces for a province
void Map::Set_Adjacent_Provinces(const int &origin_province_name, const std::set<int> &adjacent_province)
{
    provinces[origin_province_name].Set_Adjacent_Provinces(adjacent_province);
}

// Register the winner as the owner of the province
void Map::Set_Province_Owner(const int &origin_province_name, Player *player)
{
    provinces[origin_province_name].Set_Owner(player);
    player_provinces[player].insert(origin_province_name);
}

// returning map that connects players to captured provinces
std::map<Player *, std::set<int>> Map::Get_Player_provinces()
{
    return player_provinces;
}

// Returning a map that connects the name (with numerical identifier) ​​to the provinces
std::map<int, Province> Map::Get_Provinces()
{
    return provinces;
}