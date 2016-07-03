#include "Player.h"
#include <stdio.h>
#include "PRINTS.h"
#include <stdlib.h>

Player::Player(Card *playerCards)
{
    myCards = playerCards;
    remainCards = 0;

    Card *pointer = myCards;
    while(pointer != NULL)
    {
        remainCards ++;
        pointer = pointer->getNextCard();
    }
}


Player::~Player(void)
{
    clearCards();
}


void Player::showCards()
{
    char count = 0;
    Card *pointer = myCards;
    while(pointer != NULL)
    {
        PRINT_CARD(++count, pointer->getShapeColor(), pointer->getName(), pointer->getValue());
        pointer = pointer->getNextCard();
    }
}

void Player::clearCards()
{
    Card *tmp;
    while( myCards != NULL)
    {
        tmp = myCards;
        myCards = myCards->getNextCard();
        free(tmp);
    }
    remainCards = 0;
}

void Player::deleteCard(char index)
{
    #ifdef INDEX_VALUE
        if(index > remainCards || index < 0)
        {
            printf("The choosen card is out of range!\n");
        }
    #endif

    index--;
    Card *pointer = myCards;
    remainCards --;

    if(0 == index)
    {
        myCards = myCards->getNextCard();
        free(pointer);      
    }else
    {
        while(index-- > 1)
        {
            pointer = pointer->getNextCard();
        }
        Card *tmp = pointer->getNextCard();
        pointer->setNextCard(tmp->getNextCard());
        free(tmp);
    }
}

Card *Player::seekCard(char index)
{
    if(index > remainCards || index < 1)
    {
        return NULL;
    }
    Card *pointer = myCards;
    while(--index > 0)
    {
        pointer = pointer->getNextCard();
    }
    return pointer;
}

int Player::getRemainCards()
{
    return remainCards;
}

void Player::sortCard()
{
    Card *pointOuter = myCards;

    while(pointOuter->getNextCard() != NULL)
    {
        Card *pointInner = pointOuter ->getNextCard();
        while(pointInner != NULL)
        {
            if(pointInner ->getValue() < pointOuter ->getValue())
            {
                char nameTMP = pointOuter ->getName();
                char shapeTMP = pointOuter ->getShapeColor();
                char valueTMP = pointOuter ->getValue();

                pointOuter->setName(pointInner->getName());
                pointOuter->setShapeColor(pointInner->getShapeColor());
                pointOuter->setValue(pointInner->getValue());

                pointInner->setName(nameTMP);
                pointInner->setShapeColor(shapeTMP);
                pointInner->setValue(valueTMP);
            }
            pointInner = pointInner ->getNextCard();
        }
        pointOuter = pointOuter ->getNextCard();
    }
}