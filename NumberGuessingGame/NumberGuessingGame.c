/*
Author: Serly Teymoorian 
-> This game is about guessing a number to match the random number selected by the program 
-> start the program:
    -> select a random number between 1-10
    -> do while (not quit the program)
    -> if they choose to play the game
    ->      ask them to choose a number 
    ->      scanf("%d", userInput)
    ->      do while loop (not quit the game and not won)
    ->      if statement to check if userInput == randomNum 
    ->          yes 
    ->              Won 
    ->          no 
    ->              try until win 
    ->      end do while 
    -> if they choose to change the max number 
    ->      change the initial max number which was 10 
    -> if they choose to quit -> quit the program 
    -> end do while loop 
-> end the program    
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    char choose; 
    int maxNum = 10; 
    int randNum; 
    int userInput; 
    bool haveWon; 
    int numPlayedGames =0; 
    int numGuess =0;
    char* numOgGuesses[100]; 
    time_t t; 
    srand((unsigned)time(&t)); 

    do
    {
        fflush(stdin); 
        //print the menu 
        printf("\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n"); 
        scanf("%c",&choose); 

        if(choose =='1')
        {   
            ++numPlayedGames; //update the number of games played
            randNum = rand() % maxNum + 1; //choose a num btw 1-maxNum 
            haveWon = false; 
            do
            {
                printf("Choose a number between 1-%d\n", maxNum); //ask user input 
                scanf("%d", &userInput);
                ++numGuess; //update # of guesses 
                
                if(userInput == randNum)
                {
                    haveWon = true; 
                    printf("You have WON!!\n"); 
                    sprintf(numOfGuesses[numPlayedGames-1], "%d", numGuess); 
                }
                else if(userInput < 1 || userInput > maxNum)
                {
                    printf("Wrong input!!\nThe entered the number should be between 1-%d\nPlease Try again\n", maxNum);
                    sprintf(numOfGuesses[numPlayedGames-1], "%d", numGuess); 
                }
                else if(userInput == 'q')
                {
                    printf("You have decided to quit this round of game!!\n"); 
                    numOfGuesses[numPlayedGames-1] = "Lost the Game!!"; 
                }
                else 
                {
                    printf("Wrong Guess!!\nTry again\n"); 
                    sprintf(numOfGuesses[numPlayedGames-1], "%d", numGuess); 
                } 
            } while (!haveWon && userInput != 'q');
        }
        //choose a new max number 
        else if(choose == '2')
        {
            printf("What do you want the new max number be? "); 
            scanf("%d", &maxNum); 
        }
        //quit the program 
        else if(choose == '3')
        {
            printf("You have decided to quit our program.\nThank you for choosing our program."); 
            printf("\nYou have played %d games", numPlayedGames); 
            
            for(int game =0; game <numPlayedGames; ++game)
            {
                if(strcmp(numOfGuesses[game], "Lost the Game!!") ==0)
                {
                    printf("\nFor game number %d:\n%s", game + 1, numOfGuesses[game]); 
                }
                else
                {
                    printf("\nFor game number %d:\nYou had %s guesses", game + 1, numOfGuesses[game]); 
            }
        }
        //invalid user input 
        else 
        {
            printf("Invalid Input!\nPlease try again\n"); 
        }
       
    } while (choose != '3');

    return 0; 
}
