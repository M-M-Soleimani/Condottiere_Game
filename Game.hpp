#ifndef GAME_HPP
#define GAME_HPP
#include "Card.hpp"
#include "UI.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "YellowCard.hpp"
#include "Tabl_zan.hpp"
#include "Shah_dokht.hpp"
#include "Matarsak.hpp"
#include <vector>
#include "Bahar.hpp"
#include "Zemestan.hpp"

class Game
{

public:
    Game();                                                              // Game class constructor to initialize values
    ~Game();                                                             // Malicious default class Game
    void Game_Initializer();                                             // To initialize player information
    void Run_Game();                                                     // Gameplay implementation
    void Show_Help();                                                    // Show game description
    void Show_Card_Help(const std::string &);                            // Show the description of the cards
    bool Check_Game_Victory(std::shared_ptr<Player>);                    // Checking the player's victory the game
    void Set_Season(const std::string &);                                // Set Season of game
    std::string Get_Season() const;                                      // Returning Season of game
    void Set_Battlefield(const std::string &);                           // Set battlefield of game
    std::string Get_Battlefield() const;                                 // Returning battlefield of game
    int Find_Youngest_Index();                                           // Find the index of the youngest player
    int levenshtein(const std::string &, const std::string &, int, int); // levenshtein algorithm
    void Autocorrect(const std::string &);                               // It suggests the closest valid command
    bool Is_Valid_commasnd(const std::string &);                         // Checks whether the string passed to the function is valid or not
    void Play_Turn(int &);                                               // A function to do what is needed for the player to complete his turn
    void Set_Valid_Commands();                                           // set valid commands
    void Calculate_player_score(std::shared_ptr<Player> &);              // Calculation of each player's points with special rules and procedures
    void Check_Province_Winner(std::shared_ptr<Player> &);               // Checking who is the conqueror of the province and who gets the battle badge
    void Returning_Played_Cards_To_Game_Deck();                          // Played cards are returned to the deck
    void Dealing();                                                      // Dealing to each player
    void Refection();                                                    // Refection
    void Provinces_War_Initializer();                                    // Choosing the battlefield and...
    void Set_Valid_Provinces();                                          // set valid provinces
    bool Is_Valid_Province(const std::string &);                         // Checking whether the input string is a valid province or not
    void Delete_Valid_Provinces(const std::string &);                    // Removing the name of the province from valid provinces for war
    void Save(const int & ,std::shared_ptr<Player> &);
    void load();

private:
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Player>> players_turn;
    std::vector<std::shared_ptr<Card>> played_cards;
    Deck game_deck;
    Map game_map;
    static UI ui;
    std::string season = "none";
    std::string battlefield = "none";
    std::vector<std::string> valid_commands;
    std::vector<std::string> valid_provinces;
    int game_turn_indicator = 0;
};

#endif