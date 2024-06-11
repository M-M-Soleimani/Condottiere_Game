#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>

class Card
{
public:
    enum class Color
    {
        Yellow,
        Purple
    };
    Card(std::string, int, std::string, Color);
    std::string Get_Type() const;
    int Get_Value() const;
    std::string Get_Description() const;
    Color Get_Color() const;
    int Get_Score() const;
    void Set_Score(int);
    virtual bool perform_Action(std::vector<Card *> &) = 0;

private:
    std::string type;
    int value;
    int score;
    std::string description;
    Color color;
};
#endif