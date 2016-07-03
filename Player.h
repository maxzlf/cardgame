#pragma once
#include "Card.h"
class Player
{
public:
    Player(Card *playerCards);
    ~Player(void);

    Card *seekCard(char index);
    void showCards();
    void clearCards();
    void deleteCard(char index);
    void sortCard();
    int  getRemainCards();

private:
    Card *myCards;
    char remainCards;
};

