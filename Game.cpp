#include "Game.hpp"
#include "Map.hpp"
#include <random>
#include <ctime>
#include <bits/stdc++.h>
#include <climits>

UI Game::ui; // Static member

// Game class constructor to initialize values
Game::Game()
{
    ui.Clear_Window();
    Game_Initializer();
    Set_Valid_Provinces();
    Set_Valid_Commands();
}

// Malicious default class Game
Game::~Game() = default;

// To initialize player information
void Game::Game_Initializer()
{
    int number_of_players_turn = ui.Get_Number_Of_Player();

    ui.Get_Player_Informations(players, number_of_players_turn); // Get the information of each player 
    Dealing(); // Dealing to each player
    for (size_t i = 0; i < number_of_players_turn; ++i)
    {
        // Show each player's hand to it
        ui.Display_Message<std::string>(players[i]->Get_Name());
        ui.Display_Message<std::string>("'s cards will be displayed soon. Please hand over the system to him/her. (press enter to view)");
        int character = 0;
        do
        {
            character = ui.Get_Ch();
        } while (character != 13);
        ui.Clear_Window();
        ui.Display_Hand(players[i]);

        ui.Display_Message<std::string>("Press enter to continue.");
        character = 0;
        do
        {
            character = ui.Get_Ch();
        } while (character != 13);
        ui.Clear_Window();
    }
}

// Gameplay implementation
void Game::Run_Game()
{
    std::shared_ptr<Player> last_player_pass = nullptr;
    std::shared_ptr<Player> winner = nullptr;
    bool is_game_over = false;
    int game_turn_indicator = Find_Youngest_Index();
    players[game_turn_indicator]->Set_War_Badge(true); // Giving the battle badge to the youngest player
    while (true)
    {
        Provinces_War_Initializer(); // Choosing the battlefield and...
        while (players_turn.size() > 0)
        {
            ui.Clear_Window();
            ui.Display_Message<std::string>(players_turn[game_turn_indicator]->Get_Name());
            ui.Display_Message<std::string>("'s cards will be displayed soon. Please hand over the system to him/her. (press enter to view)");
            int character = 0;
            do
            {
                character = ui.Get_Ch();
            } while (character != 13);
            ui.Clear_Window();

            // Displaying game information and playing the game by the player
            ui.Show_Game_Informations(players,players_turn, game_turn_indicator, Get_Season(), Get_Battlefield());
            Play_Turn(game_turn_indicator);
            
            // Creating the order of players to play clockwise
            if (game_turn_indicator + 1 >= players_turn.size() || game_turn_indicator < 0)
            {
                game_turn_indicator = 0;
            }
            else
            {
                ++game_turn_indicator;
            }

            // When the player has no cards to play, he is removed from that round
            if (players_turn[game_turn_indicator]->Get_hand().size() == 0)
            {
                players_turn.erase(players_turn.begin() + game_turn_indicator);
                game_turn_indicator--;
            }

            // Specify the last player in the game
            if (players_turn.size() == 1)
            {
                last_player_pass = players_turn[0];
            }
        }
        Check_Province_Winner(last_player_pass); // Find the victorious player of the battlefield province
        // Restore game settings
        Returning_Played_Cards_To_Game_Deck();
        Set_Battlefield("none");
        Set_Season("none");
        Refection(); // If necessary refection
        players_turn.clear();
        // Check if a player has won or not
        for (auto player : players)
        {
            if (Check_Game_Victory(player))
            {
                is_game_over = true;
                winner = player;
                break;
            }
        }
        if (is_game_over)
        {
            break;
        }
    }
    // Display who is the winner
    ui.Display_Message<std::string>(winner->Get_Name());
    ui.Display_Message<std::string>(" Win the Game !");
}

// Show the description of the cards
void Game::Show_Card_Help(const std::string &card_name)
{
    std::vector<std::shared_ptr<Card>> playing_cards_list = game_deck.Get_Playing_Cards_List();
    for (auto it : playing_cards_list)
    {
        if ("help " + it->Get_Type() == card_name)
        {
            std::string q = it->Get_Description();
            ui.Display_Message<std::string>(q);
            break;
        }
    }
}

// Show game description
void Game::Show_Help()
{
    ui.Display_Game_Help();
}

// Set Season of game
void Game::Set_Season(const std::string &season)
{
    this->season = season;
}

// Returning Season of game
std::string Game::Get_Season() const
{
    return season;
}

// Set battlefield of game
void Game::Set_Battlefield(const std::string &battlefield)
{
    this->battlefield = battlefield;
}

// Returning battlefield of game
std::string Game::Get_Battlefield() const
{
    return battlefield;
}

// Checking the player's victory the game
bool Game::Check_Game_Victory(std::shared_ptr<Player> player)
{
    std::map<std::shared_ptr<Player>, std::set<int>> player_provinces = game_map.Get_Player_provinces();
    std::map<int, Province> provinces = game_map.Get_Provinces();
    // Survey of 5 non-adjacent provinces
    if (player_provinces[player].size() >= 5)
        return true; // player owns at least 5 provinces (adjacent or non-adjacent).

    // Survey of 3 neighboring provinces
    for (auto &province : player_provinces[player])
    {
        int adjacent_count = 1;
        for (auto &origin_province_name : provinces[province].Get_Adjacent_Provinces())
            if (provinces[origin_province_name].Get_Owner() == player)
                adjacent_count++;

        if (adjacent_count >= 3)
            return true; // player owns at least 3 neighboring provinces
    }

    return false; // The player has not won
}

// Find the index of the youngest player
int Game::Find_Youngest_Index()
{
    // Browse to find the youngest player
    int min_age = 0;
    bool is_first = true;
    for (auto player : players)
    {
        if (is_first)
        {
            min_age = player->Get_Age();
            is_first = false;
            continue;
        }
        if (player->Get_Age() < min_age)
        {
            min_age = player->Get_Age();
        }
    }

    // If several players of the same age share the lowest age, one of them is randomly selected
    std::vector<int> same_age_players_index;
    int i = 0;
    for (auto player : players)
    {
        if (player->Get_Age() == min_age)
        {
            same_age_players_index.push_back(i);
        }
        ++i;
    }

    srand(time(0));
    return same_age_players_index[(rand() % same_age_players_index.size())];
}

// levenshtein algorithm
int Game::levenshtein(const std::string &str1, const std::string &str2, int str1_size, int str2_size)
{
    // str1 is empty
    if (str1_size == 0)
    {
        return str2_size;
    }
    // str2 is empty
    if (str2_size == 0)
    {
        return str1_size;
    }

    if (str1[str1_size - 1] == str2[str2_size - 1])
    {
        return levenshtein(str1, str2, str1_size - 1, str2_size - 1);
    }
    //         Insert                                                      Remove                                                      Replace
    return 1 + std::min(levenshtein(str1, str2, str1_size, str2_size - 1), std::min(levenshtein(str1, str2, str1_size - 1, str2_size), levenshtein(str1, str2, str1_size - 1, str2_size - 1)));
}

// It suggests the closest valid command
void Game::Autocorrect(const std::string &choice)
{
    std::vector<int> commands_spell_difference;
    // Calling the levenshtein algorithm for all valid and input commands to find the smallest difference
    for (auto command : valid_commands)
    {
        commands_spell_difference.push_back(levenshtein(choice, command, choice.length(), command.length()));
    }
    int i = 0;
    int min_difference_index = 0;
    bool is_first = true;
    for (auto command_spell_difference : commands_spell_difference)
    {
        if (is_first)
        {
            min_difference_index = i;
        }
        is_first = false;
        if (command_spell_difference <= commands_spell_difference[min_difference_index])
        {
            min_difference_index = i;
        }
        ++i;
    }

    ui.Display_Message<std::string>("Did you mean ");
    ui.Display_Message<std::string>(valid_commands[min_difference_index]);
    ui.Display_Message<std::string>(" ? ");
}

// Checks whether the string passed to the function is valid or not
bool Game::Is_Valid_commasnd(const std::string &choice)
{
    bool is_correct = false;
    for (auto command : valid_commands)
    {
        if (choice == command)
        {
            is_correct = true;
            break;
        }
    }
    return is_correct;
}

// A function to do what is needed for the player to complete his turn
void Game::Play_Turn(int &game_turn_indicator)
{
    bool is_operation_done = false;
    do
    {
        // Receiving input from the user and checking whether the command is valid or not
        std::string choice = ui.Get_Line_Tolower();
        bool is_correct = Is_Valid_commasnd(choice);

        std::string sub_choice = choice.substr(0, 5);
        if (is_correct)
        {
            if (choice == "pass")
            {
                players_turn.erase(players_turn.begin() + game_turn_indicator);
                game_turn_indicator--;
                is_operation_done = true;
            }
            else if (choice == "help")
            {
                ui.Clear_Window();
                Show_Help();
                ui.Display_Message<std::string>("Press esc to exit");
                int character = 0;
                do
                {
                    character = ui.Get_Ch();
                } while (character != 27);
                ui.Clear_Window();
                ui.Show_Game_Informations(players,players_turn, game_turn_indicator, Get_Season(), Get_Battlefield());
                is_operation_done = true;
            }
            else if (sub_choice == "help ")
            {
                ui.Clear_Window();
                Show_Card_Help(choice);
                ui.Display_Message<std::string>("Press esc to exit");
                int character = 0;
                do
                {
                    character = ui.Get_Ch();
                } while (character != 27);
                ui.Clear_Window();
                ui.Show_Game_Informations(players,players_turn, game_turn_indicator, Get_Season(), Get_Battlefield());
                is_operation_done = true;
            }
            else
            {
                for (auto card : players_turn[game_turn_indicator]->Get_hand())
                {
                    if (choice == card->Get_Type())
                    {
                        if (card->Get_Color() == Card::Color::Yellow || card->Get_Type() == "shah_dokht")
                        {
                            card->perform_Action();
                        }
                        else if (card->Get_Type() == "matarsak")
                        {
                            card->perform_Action(players_turn[game_turn_indicator]);
                        }
                        else if (card->Get_Type() == "bahar" || card->Get_Type() == "zemestan")
                        {
                            Set_Season(card->Get_Type());
                        }
                        played_cards.push_back(players_turn[game_turn_indicator]->Play_Card(choice));
                        is_operation_done = true;
                        break;
                    }
                }
                if (!is_operation_done)
                {
                    ui.Display_Message<std::string>("Such a card is not available, enter another card : ");
                }
            }
        }
        else
        {
            Autocorrect(choice);
        }

    } while (!is_operation_done);
}

// set valid commands
void Game::Set_Valid_Commands()
{
    valid_commands.push_back("1");
    valid_commands.push_back("2");
    valid_commands.push_back("3");
    valid_commands.push_back("4");
    valid_commands.push_back("5");
    valid_commands.push_back("6");
    valid_commands.push_back("10");
    valid_commands.push_back("matarsak");
    valid_commands.push_back("bahar");
    valid_commands.push_back("zemestan");
    valid_commands.push_back("shah_dokht");
    valid_commands.push_back("tabl_zan");
    valid_commands.push_back("pass");
    valid_commands.push_back("help");
    valid_commands.push_back("help 1");
    valid_commands.push_back("help 2");
    valid_commands.push_back("help 3");
    valid_commands.push_back("help 4");
    valid_commands.push_back("help 5");
    valid_commands.push_back("help 6");
    valid_commands.push_back("help 10");
    valid_commands.push_back("help matarsak");
    valid_commands.push_back("help bahar");
    valid_commands.push_back("help zemestan");
    valid_commands.push_back("help shah_dokht");
    valid_commands.push_back("help tabl_zan");
}

// Calculation of each player's points with special rules and procedures
void Game::Calculate_player_score(std::shared_ptr<Player> &player)
{
    // Checking whether the player used the tabl_zan card or not
    bool tabl_zan_played = false;
    for (auto card : player->Get_played_crads())
    {
        if (card->Get_Type() == "tabl_zan")
        {
            tabl_zan_played = true;
            break;
        }
    }
    
    // If the game season is zemestan, the zemestan function is called
    if (Get_Season() == "zemestan")
    {
        Zemestan zemestan;
        zemestan.perform_Action(players);
    }

    // If the tabl_zan card is played, the tabl_zan function is called
    if (tabl_zan_played)
    {
        Tabl_zan tabl_zan;
        tabl_zan.perform_Action(player);
    }

    // If the game season is bahar, the bahar function is called
    if (Get_Season() == "bahar")
    {
        Bahar bahar;
        bahar.perform_Action(players);
    }

    // This section collects points
    int total_score = 0;
    for (auto card : player->Get_played_crads())
    {
        if (card->Get_Color() == Card::Color::Yellow || card->Get_Type() == "shah_dokht")
        {
            total_score += card->Get_Score();
        }
    }
    player->Set_Score(total_score);
}

// Checking who is the conqueror of the province and who gets the battle badge
void Game::Check_Province_Winner(std::shared_ptr<Player> &last_player_pass)
{
    // The score of all players is calculated
    for (auto it : players)
    {
        Calculate_player_score(it);
    }
    // The highest score is determined
    int max_score = 0;
    for (auto it : players)
    {
        if (it->Get_Score() > max_score)
        {
            max_score = it->Get_Score();
        }
    }
    // If several people have won the most points at the same time,
    // no one will win the province and the battle badge will go to the last person who was in the game
    std::shared_ptr<Player> winner = nullptr;
    int max_score_players_counter = 0;
    for (auto it : players)
    {
        if (it->Get_Score() == max_score)
        {
            winner = it;
            max_score_players_counter++;
        }
    }
    if (max_score_players_counter == 1)
    {
        winner->Set_War_Badge(true);
        game_map.Set_Province_Owner(Get_Battlefield(), winner);
        Delete_Valid_Provinces(Get_Battlefield());
    }
    else
    {
        last_player_pass->Set_War_Badge(true);
    }
}

// Played cards are returned to the deck
void Game::Returning_Played_Cards_To_Game_Deck()
{
    for (auto card : played_cards)
    {
        game_deck.Add_Card(card);
    }
    played_cards.clear();
    game_deck.Shuffle();
}

// Dealing to each player
void Game::Dealing()
{
    Returning_Played_Cards_To_Game_Deck();
    for (auto player : players)
    {
        for (size_t j = 0; j < 10 + ((player->Get_Acquired_Provinces()).size()); ++j)
        {
            player->Add_Card(game_deck.Draw_Card());
        }
    }
}

// Refection
void Game::Refection()
{
    // search on player to find those who are empty or just have a purple card
    int player_with_no_soldier_cards_number = 0;
    for (auto player : players)
    {
        int number_of_cards = 0;
        number_of_cards = player->Get_hand().size();
        if (number_of_cards == 0)
        {
            ++player_with_no_soldier_cards_number;
        }
        else
        {
            bool soldier_in_hand = false;
            for (auto card : player->Get_hand())
            {
                if (card->Get_Color() == Card::Color::Yellow)
                {
                    soldier_in_hand = true;
                    break;
                }
            }
            // If they only have a purple card, they will be asked if they want to burn their hand or not
            if (!soldier_in_hand)
            {
                ui.Clear_Window();
                ui.Display_Message<std::string>(player->Get_Name());
                ui.Display_Message<std::string>("'s cards will be displayed soon. Please hand over the system to him/her. (press enter to view)");
                int character = 0;
                do
                {
                    character = ui.Get_Ch();
                } while (character != 13);
                ui.Clear_Window();
                ui.Display_Hand(player);
                ui.Display_Message<std::string>("You have no soldier card in your hand, do you want to burn your hand ?\n");
                ui.Display_Message<std::string>("(y)es or (n)o ?");
                bool is_operation_done = false;
                do
                {
                    int choice = ui.Get_Ch();
                    if (choice == 121 || choice == 89)
                    {
                        is_operation_done = true;
                        player->burning_Hand(played_cards);
                        ++player_with_no_soldier_cards_number;
                    }
                    else if (choice == 110 || choice == 78)
                    {
                        is_operation_done = true;
                        ++player_with_no_soldier_cards_number;
                    }
                } while (!is_operation_done);
                Returning_Played_Cards_To_Game_Deck();
                ui.Clear_Window();
            }
        }
    }
    //If all players do not have cards, cards are dealt again
    if (player_with_no_soldier_cards_number == players.size())
    {
        Dealing();
    }
    // If only one player has a card, his hand is burned and the card is dealt again
    else if (player_with_no_soldier_cards_number == players.size() - 1)
    {
        for (auto player : players)
        {
            if (player->Get_hand().size() != 0)
            {
                ui.Clear_Window();
                ui.Display_Hand(player);
                ui.Display_Message<std::string>("You are the only player with cards, unfortunately you have to burn your hand (this is done automatically)\n");
                player->burning_Hand(played_cards);
                Returning_Played_Cards_To_Game_Deck();
                ui.Display_Message<std::string>("Press enter to continue.");
                int character = 0;
                do
                {
                    character = ui.Get_Ch();
                } while (character != 13);
                ui.Clear_Window();
                break;
            }
        }
        Dealing();
    }
}

// Choosing the battlefield and...
void Game::Provinces_War_Initializer()
{
    // Find someone with a battle badge to mark the battlefield
    for (auto it : players)
    {
        if (it->Get_War_Badge() == true)
        {
            ui.Display_Message<std::string>(it->Get_Name());
            ui.Display_Message<std::string>(" Enter the desired province for the war : ");
            system("start ./map.png"); // Open the game map image
            std::string choice;
            bool is_operation_done = false;
            // Choosing a valid province as a battlefield
            do
            {
                choice = ui.Get_Line_Toupper();
                if (!Is_Valid_Province(choice))
                {
                    Autocorrect(choice);
                }
                else
                {
                    is_operation_done = true;
                }
            } while (!is_operation_done);

            Set_Battlefield(choice);
            it->Set_War_Badge(false);
            break;
        }
    }

    for (auto player : players)
    {
        players_turn.push_back(player);
    }
}

// set valid provinces
void Game::Set_Valid_Provinces()
{
    valid_provinces.push_back("BELLA");
    valid_provinces.push_back("CALINE");
    valid_provinces.push_back("ENNA");
    valid_provinces.push_back("ATELA");
    valid_provinces.push_back("PLADACI");
    valid_provinces.push_back("BORGE");
    valid_provinces.push_back("DIMASE");
    valid_provinces.push_back("MORINA");
    valid_provinces.push_back("OLIVADI");
    valid_provinces.push_back("ROLLO");
    valid_provinces.push_back("TALMONE");
    valid_provinces.push_back("ARMENTO");
    valid_provinces.push_back("LIA");
    valid_provinces.push_back("ELINA");
}

// Checking whether the input string is a valid province or not
bool Game::Is_Valid_Province(const std::string &choice)
{
    bool is_correct = false;
    for (auto command : valid_provinces)
    {
        if (choice == command)
        {
            is_correct = true;
            break;
        }
    }
    return is_correct;
}

// Removing the name of the province from valid provinces for war
void Game::Delete_Valid_Provinces(const std::string &choice)
{
    int index = 0;
    for(auto province : valid_provinces)
    {
        if (province == choice)
        {
            break;
        }
        ++index;
    }
    valid_provinces.erase(valid_provinces.begin()+index);
}