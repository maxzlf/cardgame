#include <stdio.h>
#include <iostream>
#include "SortCard.h"
#include "Card.h"
#include "Player.h"
#include <ctime>
#include <WinError.h>

int PK(int value1, int value2)
{
    if( (value1 >= 11 && value1 <= 13) || (value2 >= 11 && value2 <= 13) )
    {
        return 0;
    }else
    {
        return value1 - value2;
    }
}

/**
 * check whether the input is legal
 * if the input is legal, return the
 * value of input
 * else return -1 for error, 0 for none
**/
int input(char *str)
{
    int strLength = strlen(str);
    if(0 == strLength)
    {
        return 0;
    }else if(strLength > 2)
    {
        return -1;
    }


    if(1 == strLength)
    {
        if(str[0] >= '0' && str[0] <= '9')
        {
            return str[0] - '0';
        }else
        {
            return -1;
        }
    }else
    {
        if(str[0] >= '0' && str[0] <= '9' && str[1] >= '0' && str[1] <= '9')
        {
            return (str[0]-'0')*10 + (str[1]-'0');
        }else
        {
            return -1;
        }
    }
}

void game()
{
    srand((unsigned)time(0));
    while(true)
    {
        char play[10];
        printf("You are welcom!\n");
        printf("Press 1 to play the game;\n");
        printf("Press others to quit the game;\n");
        printf("You enter : \n");
        scanf("%s", play);
        if(1 != input(play))
        {
            return;
        }
        printf("START GAME!\n\n");


        SortCard sortCard;
        sortCard.initCards();
        Player me(sortCard.getMyCards());
        Player computer(sortCard.getYourCards());
        me.sortCard();

        while(true)
        {
            me.showCards();
            printf("Please choose your card:\n");
            char chose[10];
            int chosen = 1;

            scanf("%s", chose);
            chosen = input(chose);
            while( chosen < 1 ||  chosen > me.getRemainCards() )
            {
                printf("Please input from 1 to %d to chose your card:\n", me.getRemainCards());
                scanf("%s", chose);
                chosen = input(chose);
            }
            int computerIndex = rand() % computer.getRemainCards() + 1;
            Card *myCard = me.seekCard( chosen );    
            Card *computerCard = computer.seekCard(computerIndex);

            if( NULL == myCard || NULL == computerCard)
            {
                printf("Eh, an error!\n");
                exit(0);
            }
            printf("You chosed %c:\n", myCard->getName());
            printf("Com chosed %c:\n", computerCard->getName());

            int pk = PK(myCard->getValue(), computerCard->getValue());
            if( pk > 0 )
            {
                computer.deleteCard(computerIndex);
                printf("You Win!\n");
            }else if( pk == 0 )
            {
                me.deleteCard( chosen );
                computer.deleteCard(computerIndex);
                printf("Tie!\n");
            }else
            {
                me.deleteCard( chosen );
                printf("You Fail!\n");
            }
            printf("----------------------------------------------------\n");   
            if( 0 == me.getRemainCards() && computer.getRemainCards() > 0)
            {
                printf("Sorry, You lose the game!\n");   
                printf("====================================================\n"); 
                break;
            }else if(0 == computer.getRemainCards() && me.getRemainCards() > 0)
            {
                printf("Congratulations! You win the game!\n");
                printf("====================================================\n"); 
                break;
            }else if(0 == computer.getRemainCards() == me.getRemainCards()) 
            {
                printf("Not bad! Tie!\n");
                printf("====================================================\n"); 
                break;                
            }     

        }// end of inner while
    }// end of outer while
}

int main(int argc, char *argv[])
{
    game();
}