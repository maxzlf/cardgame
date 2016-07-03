#include "Card.h"
#include "DEBUG.h"
#include <iostream>

Card::Card(char sc, char val)
{
    nextCard = NULL;

    shapeColor = sc;
    if( sc > 6 || sc < 3)
    {
        #ifdef CARD_VALUE
            std::cout<<"The card shape hasn't been defined!";
        #endif
    }

    value = val;
    if( value >= 1 && value <= 9)
    {
        name = value + '0';
    }else if( 10 == value)
    {
        name = 'T';
    }else if( 11 == value)
    {
        name = 'J';
    }else if( 12 == value)
    {
        name = 'Q';
    }else if( 13 == value)
    {
        name = 'K';
    }else
    {
        #ifdef CARD_VALUE
            std::cout<<"The card value is out of range!";
        #endif
    }
}


Card::~Card(void)
{
}


char Card::getName()
{
    return name;
}

char Card::getShapeColor()
{
    return shapeColor;
}

int Card::getValue()
{
    return value;
}

Card* Card::getNextCard()
{
    return nextCard;
}


void Card::setShapeColor(char shape)
{
    shapeColor = shape;
}

void Card::setName(char name_)
{
    name = name_;
}

void Card::setValue(char value_)
{
    value = value_;
}

void Card::setNextCard(Card *next)
{
    nextCard = next;
}