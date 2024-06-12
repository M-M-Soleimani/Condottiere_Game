#include "Card.hpp"
#include "Tabl_zan.hpp"

// Constructor to create an instance of class Tabl_zan
Tabl_zan::Tabl_zan() 
: Card::Card("tabl_zan" ,0 ,"When a player plays the female drummer, the total number of his soldiers (yellow) is doubled.\nFor example, a player who has a 2nd soldier and a 6th soldier in his army ranks with the game\nDrumming changes the total number of his army from 8 to 16.\ntip:\nOnly one Drummer card affects each player's army per battle.\nMore than one female drum can be played, but it has no effect.\n" ,Color::Purple ){}

//  An overridden function to double the value of all cards played by the user
bool Tabl_zan::perform_Action(std::vector<Card *> &playerCard)
{
    for (Card *card : playerCard)
    {
        if (card->Get_Color() == Card::Color::Yellow)
        {
            int new_score = card->Get_Value() * 2;
            card->Set_Score(new_score);
        }
    }
    return true;
}