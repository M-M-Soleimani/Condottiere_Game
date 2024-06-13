#include "Matarsak.hpp"
#include "Card.hpp"
#include "UI.hpp"

// A constructor to initialize and create an instance of the Matarsak class
Matarsak::Matarsak() : Card::Card("matarsak", 0, "When a player plays a matarsak, he can be one of his soldiers (yellow cards).\ntake it from the ranks of his army and put it back in his hand.\ntip:\nSpecial (purple) cards cannot be returned to the hand with matarsak.\n", Color::Purple) {}

// Implementation of the function of returning the card to the user
bool Matarsak::perform_Action(std::vector<Card *> &playerCard)
{
    UI ui;
    ui.Display_Message("Enter a card to return it to the card deck :");
    std::string choice = ui.Get_User_Input<std::string>();

    Card *temp_ptr;
    for (size_t i = 0; i < playerCard.size(); i++)
    {
        if (playerCard[i]->Get_Type() == choice)
        {
            // temp_ptr = playerCard[i];
            // playerCard.erase(playerCard.begin() + i);
            // break;

            // TO_DO : Implementation of the logic of returning the card to the user
        }
    }
    return true;
}