#include "SortCard.h"
#include <stdlib.h>
#include <ctime>
#include <stdio.h>

SortCard::SortCard(void)
{
    initialCards = NULL;
    myCards = NULL;
    yourCards = NULL;
    count = TOTAL_CARDS;
}


SortCard::~SortCard(void)
{
}


void SortCard::initCards()
{
    Card *tail = NULL;
    char value;
    for(value=1; value<=CARD_RANGE; value++)
    {
        char colorShape;
        for(colorShape=3; colorShape<=6; colorShape++)
        {
            Card *card = new Card(colorShape, value);
            if(NULL == initialCards)
            {
                initialCards = card;
                tail = initialCards;
            }else
            {
                tail->setNextCard(card);
                tail = card;
            }
        }
    }
}

Card *SortCard::removeCard()
{
    if(0 >= count)
    {
        return NULL;
    }
    srand((unsigned)time(0));
    char seek = rand() % count--;
    Card *pointer = initialCards;

    if( 0 == seek )
    {
        Card *answer = initialCards;
        initialCards = initialCards->getNextCard();
        return answer;
    }else
    {
        while(seek-- > 1)
        {
            pointer = pointer->getNextCard();
        }
        Card *answer = pointer->getNextCard();
        pointer->setNextCard(pointer->getNextCard()->getNextCard());
        return answer;
    }   
}

Card *SortCard::getPlayerCards()
{
    Card *playerCards = NULL;
    char c = TOTAL_CARDS/2;
    Card *tail = NULL;
    while( c-- > 0)
    {
        Card *card = removeCard();
        #ifdef VALID_CARD
            printf("ERROR!--VALID CARD!");
        #endif
        if(NULL == playerCards)
        {
            playerCards = card;
            tail = playerCards;
        }else
        {
            tail->setNextCard(card);
            tail = card;
        }
    }
    tail->setNextCard(NULL);
    return playerCards;
}

Card *SortCard::getMyCards()
{
    myCards = getPlayerCards();
    return myCards;
}

Card *SortCard::getYourCards()
{
    yourCards = getPlayerCards();
    return yourCards;
}

void SortCard::clearCards()
{
    initialCards = NULL;
    myCards = NULL;
    yourCards = NULL;
}
