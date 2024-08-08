#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>
#include <memory>
class Player; // Forward declare
class Game;   // Forward declare

class Card
{
public:
    enum class Color
    {
        Yellow,
        Purple
    };
    Card(std::string, int, std::string, Color); // Class constructor for parameter initialization
    std::string Get_Type() const;               // Return card type
    int Get_Value() const;                      // Return card value
    std::string Get_Description() const;        // Return card description
    Color Get_Color() const;                    // Return card color
    int Get_Score() const;                      // Return card score
    void Set_Score(int);                        // Set the value of the score with the input parameter
    // Override and overload functions to implement the capabilities of each card
    virtual std::string perform_Action() = 0;
    virtual std::string perform_Action(std::shared_ptr<Player> &) = 0;
    virtual std::string perform_Action(std::vector<std::shared_ptr<Card>> &) = 0;

private:
    std::string type;
    int value;
    int score;
    std::string description;
    Color color;
};

#endif