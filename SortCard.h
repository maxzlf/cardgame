#pragma once
#include "Card.h"
#include "VALUES.h"
class SortCard
{
public:
    SortCard(void);
    ~SortCard(void);

    void initCards(); 
    void clearCards();
    Card *getMyCards();
    Card *getYourCards();

private:
    Card *initialCards;
    Card *myCards;
    Card *yourCards;
    int   count;
    const static int TOTAL_CARDS = 4*CARD_RANGE;

    Card *removeCard();
    Card *getPlayerCards();
};

