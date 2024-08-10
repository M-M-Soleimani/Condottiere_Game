#include "Map.hpp"

// The constructor of the Map class with default values
Map::Map()
{
    Map_Initializer();
}

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
void Map::Set_Province_Owner(const std::string &origin_province_name, std::shared_ptr<Player> player)
{
    int origin_province_number = -1;
    if (origin_province_name == "BELLA")
    {
        origin_province_number = (int)Map::province::BELLA;
    }
    else if (origin_province_name == "CALINE")
    {
        origin_province_number = (int)Map::province::CALINE;
    }
    else if (origin_province_name == "ENNA")
    {
        origin_province_number = (int)Map::province::ENNA;
    }
    else if (origin_province_name == "ATELA")
    {
        origin_province_number = (int)Map::province::ATELA;
    }
    else if (origin_province_name == "PLADACI")
    {
        origin_province_number = (int)Map::province::PLADACI;
    }
    else if (origin_province_name == "BORGE")
    {
        origin_province_number = (int)Map::province::BORGE;
    }
    else if (origin_province_name == "DIMASE")
    {
        origin_province_number = (int)Map::province::DIMASE;
    }
    else if (origin_province_name == "MORINA")
    {
        origin_province_number = (int)Map::province::MORINA;
    }
    else if (origin_province_name == "OLIVADI")
    {
        origin_province_number = (int)Map::province::OLIVADI;
    }
    else if (origin_province_name == "ROLLO")
    {
        origin_province_number = (int)Map::province::ROLLO;
    }
    else if (origin_province_name == "TALMONE")
    {
        origin_province_number = (int)Map::province::TALMONE;
    }
    else if (origin_province_name == "ARMENTO")
    {
        origin_province_number = (int)Map::province::ARMENTO;
    }
    else if (origin_province_name == "LIA")
    {
        origin_province_number = (int)Map::province::LIA;
    }
    else if (origin_province_name == "ELINA")
    {
        origin_province_number = (int)Map::province::ELINA;
    }
    else if (origin_province_name == "MATIN")
    {
        origin_province_number = (int)Map::province::MATIN;
    }

    provinces[origin_province_number].Set_Owner(player);
    player_provinces[player].insert(origin_province_number);
    player->Add_Acquired_Provinces(provinces[origin_province_number].Get_Name());
}

// returning map that connects players to captured provinces
std::map<std::shared_ptr<Player>, std::set<int>> Map::Get_Player_provinces()
{
    return player_provinces;
}

// Returning a map that connects the name (with numerical identifier) ​​to the provinces
std::map<int, Province> Map::Get_Provinces()
{
    return provinces;
}

// Add provinces and adjust neighboring provinces
void Map::Map_Initializer()
{
    Add_Province((int)Map::province::BELLA, Province("BELLA"));
    Set_Adjacent_Provinces((int)Map::province::BELLA, {(int)Map::province::CALINE, (int)Map::province::PLADACI, (int)Map::province::BORGE});

    Add_Province((int)Map::province::CALINE, Province("CALINE"));
    Set_Adjacent_Provinces((int)Map::province::CALINE, {(int)Map::province::BELLA, (int)Map::province::ENNA, (int)Map::province::BORGE, (int)Map::province::PLADACI});

    Add_Province((int)Map::province::LIA, Province("ENNA"));
    Set_Adjacent_Provinces((int)Map::province::ENNA, {(int)Map::province::CALINE, (int)Map::province::ATELA, (int)Map::province::DIMASE, (int)Map::province::BORGE});

    Add_Province((int)Map::province::ATELA, Province("ATELA"));
    Set_Adjacent_Provinces((int)Map::province::ATELA, {(int)Map::province::CALINE, (int)Map::province::ENNA, (int)Map::province::DIMASE});

    Add_Province((int)Map::province::PLADACI, Province("PLADACI"));
    Set_Adjacent_Provinces((int)Map::province::PLADACI, {(int)Map::province::BELLA, (int)Map::province::CALINE, (int)Map::province::BORGE, (int)Map::province::MORINA, (int)Map::province::ROLLO});

    Add_Province((int)Map::province::BORGE, Province("BORGE"));
    Set_Adjacent_Provinces((int)Map::province::BORGE, {(int)Map::province::BELLA, (int)Map::province::CALINE, (int)Map::province::ENNA, (int)Map::province::DIMASE, (int)Map::province::OLIVADI, (int)Map::province::MORINA, (int)Map::province::PLADACI});

    Add_Province((int)Map::province::DIMASE, Province("DIMASE"));
    Set_Adjacent_Provinces((int)Map::province::DIMASE, {(int)Map::province::ENNA, (int)Map::province::ATELA, (int)Map::province::OLIVADI, (int)Map::province::MORINA, (int)Map::province::BORGE});

    Add_Province((int)Map::province::MORINA, Province("MORINA"));
    Set_Adjacent_Provinces((int)Map::province::MORINA, {(int)Map::province::PLADACI, (int)Map::province::BORGE, (int)Map::province::OLIVADI, (int)Map::province::ARMENTO, (int)Map::province::TALMONE, (int)Map::province::ROLLO});

    Add_Province((int)Map::province::OLIVADI, Province("OLIVADI"));
    Set_Adjacent_Provinces((int)Map::province::OLIVADI, {(int)Map::province::BORGE, (int)Map::province::DIMASE, (int)Map::province::LIA, (int)Map::province::ARMENTO, (int)Map::province::MORINA});

    Add_Province((int)Map::province::ROLLO, Province("ROLLO"));
    Set_Adjacent_Provinces((int)Map::province::ROLLO, {(int)Map::province::PLADACI, (int)Map::province::MORINA, (int)Map::province::TALMONE, (int)Map::province::ELINA});

    Add_Province((int)Map::province::TALMONE, Province("TALMONE"));
    Set_Adjacent_Provinces((int)Map::province::TALMONE, {(int)Map::province::ARMENTO, (int)Map::province::MORINA, (int)Map::province::ROLLO, (int)Map::province::ELINA});

    Add_Province((int)Map::province::ARMENTO, Province("ARMENTO"));
    Set_Adjacent_Provinces((int)Map::province::ARMENTO, {(int)Map::province::LIA, (int)Map::province::OLIVADI, (int)Map::province::MORINA, (int)Map::province::TALMONE});

    Add_Province((int)Map::province::ENNA, Province("LIA"));
    Set_Adjacent_Provinces((int)Map::province::LIA, {(int)Map::province::ARMENTO, (int)Map::province::OLIVADI});

    Add_Province((int)Map::province::ELINA, Province("ELINA"));
    Set_Adjacent_Provinces((int)Map::province::ELINA, {(int)Map::province::ROLLO, (int)Map::province::TALMONE});

    Add_Province((int)Map::province::MATIN, Province("MATIN"));
    Set_Adjacent_Provinces((int)Map::province::MATIN, {(int)Map::province::ATELA, (int)Map::province::DIMASE});
}

// Set province have peace sign or not
void Map::Set_Peace_Sign(const std::string &province_name, const bool &peace_sign)
{
    int province_number = -1;
    if (province_name == "BELLA")
    {
        province_number = (int)Map::province::BELLA;
    }
    else if (province_name == "CALINE")
    {
        province_number = (int)Map::province::CALINE;
    }
    else if (province_name == "ENNA")
    {
        province_number = (int)Map::province::ENNA;
    }
    else if (province_name == "ATELA")
    {
        province_number = (int)Map::province::ATELA;
    }
    else if (province_name == "PLADACI")
    {
        province_number = (int)Map::province::PLADACI;
    }
    else if (province_name == "BORGE")
    {
        province_number = (int)Map::province::BORGE;
    }
    else if (province_name == "DIMASE")
    {
        province_number = (int)Map::province::DIMASE;
    }
    else if (province_name == "MORINA")
    {
        province_number = (int)Map::province::MORINA;
    }
    else if (province_name == "OLIVADI")
    {
        province_number = (int)Map::province::OLIVADI;
    }
    else if (province_name == "ROLLO")
    {
        province_number = (int)Map::province::ROLLO;
    }
    else if (province_name == "TALMONE")
    {
        province_number = (int)Map::province::TALMONE;
    }
    else if (province_name == "ARMENTO")
    {
        province_number = (int)Map::province::ARMENTO;
    }
    else if (province_name == "LIA")
    {
        province_number = (int)Map::province::LIA;
    }
    else if (province_name == "ELINA")
    {
        province_number = (int)Map::province::ELINA;
    }
    else if (province_name == "MATIN")
    {
        province_number = (int)Map::province::MATIN;
    }

    provinces[province_number].Set_Peace_Sign(true);
}

// Returns whether the peace sign has been placed in this province or not
bool Map::Get_Peace_Sign(const std::string &province_name)
{
    int province_number = -1;
    if (province_name == "BELLA")
    {
        province_number = (int)Map::province::BELLA;
    }
    else if (province_name == "CALINE")
    {
        province_number = (int)Map::province::CALINE;
    }
    else if (province_name == "ENNA")
    {
        province_number = (int)Map::province::ENNA;
    }
    else if (province_name == "ATELA")
    {
        province_number = (int)Map::province::ATELA;
    }
    else if (province_name == "PLADACI")
    {
        province_number = (int)Map::province::PLADACI;
    }
    else if (province_name == "BORGE")
    {
        province_number = (int)Map::province::BORGE;
    }
    else if (province_name == "DIMASE")
    {
        province_number = (int)Map::province::DIMASE;
    }
    else if (province_name == "MORINA")
    {
        province_number = (int)Map::province::MORINA;
    }
    else if (province_name == "OLIVADI")
    {
        province_number = (int)Map::province::OLIVADI;
    }
    else if (province_name == "ROLLO")
    {
        province_number = (int)Map::province::ROLLO;
    }
    else if (province_name == "TALMONE")
    {
        province_number = (int)Map::province::TALMONE;
    }
    else if (province_name == "ARMENTO")
    {
        province_number = (int)Map::province::ARMENTO;
    }
    else if (province_name == "LIA")
    {
        province_number = (int)Map::province::LIA;
    }
    else if (province_name == "ELINA")
    {
        province_number = (int)Map::province::ELINA;
    }
    else if (province_name == "MATIN")
    {
        province_number = (int)Map::province::MATIN;
    }

    return provinces[province_number].Get_Peace_Sign();
}