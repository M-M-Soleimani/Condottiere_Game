#include "Matarsak.hpp"
#include "Card.hpp"
#include "UI.hpp"
#include "Player.hpp"

// constructor to initialize and create an instance of the Matarsak class
Matarsak::Matarsak() : Card::Card("matarsak", 0, "When a player plays a matarsak, he can be one of his soldiers (yellow cards).\ntake it from the ranks of his army and put it back in his hand.\ntip:\nSpecial (purple) cards cannot be returned to the hand with matarsak.\n", Color::Purple) {}

// Returning the card to the user
std::string Matarsak::perform_Action(std::shared_ptr<Player> &player)
{
    UI ui;
    ui.Display_Message<std::string>("Enter a card to return it to your hand: ");
    std::string choice = ui.Get_User_Input<std::string>();

    std::vector<std::shared_ptr<Card>> &played_cards = player->Get_played_crads(); // Get a reference to the vector

    // Find the card with the specified type
    for (size_t i = 0; i < played_cards.size(); i++)
    {
        if (played_cards[i]->Get_Type() == choice)
        {
            // Found the card, move it back to the player's hand
            player->Add_Card(played_cards[i]);
            played_cards.erase(played_cards.begin() + i); // Erase the card from the vector
            return Get_Type();
        }
    }
    ui.Display_Error("Card not found in played cards !");
    return "Card not found in played cards !";
}

// To handle the absence of errors due to overload and override
std::string Matarsak::perform_Action(std::vector<std::shared_ptr<Player>> &players)
{
    return NULL;
}

// To handle the absence of errors due to overload and override
std::string Matarsak::perform_Action()
{
    return NULL;
}