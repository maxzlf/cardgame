#pragma once
class Card
{
public:
    Card(char shapeColor, char value);
    ~Card(void);

    char getShapeColor();
    char getName();
    int  getValue();
    Card *getNextCard();

    void setShapeColor(char shape);
    void setName(char name);
    void setValue(char value);
    void setNextCard(Card *next);

private:
    char shapeColor;
    char name;
    char value;
    Card *nextCard;
};

