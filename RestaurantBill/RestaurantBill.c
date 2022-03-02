/*
Author: Serly Teymoorian 
RESTAURANT BILL:
-> This programs tries to compute tax, tip, meal cost, and overall cost for the patron
-> enter tax tip on command line for the input 
-> Use Pseudo Random to choose a meal from: Salad, Soup, Sandwich, and Pizza 
-> use if else statements 
->      if salad 
->          mealcost :=  $9.95 
->      if soup 
->          mealcost := $4.55
->      if Sandwich 
->          mealcost := 13.25
->      if Pizza
->          mealcost := 22.35 
->      
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char *argv[2])
{
    if(strtod(argv[1], NULL) < 0 || strtod(argv[2], NULL) < 0)
    {
        printf("Wrong input!!!\nTax and Tip cannot be negative!!!!\n");
        return 0; 
    }
    time_t t;  
    char meals[100]; 
    double mealCost; //cost of the meals 
    double tax = 0.0; 
    double tip = 0.0; 
    double totalCost = 0.0; 
    srand((unsigned) time(&t)); 
    int randMeal = 0; 

    randMeal = rand() % 4; //choose # btw 0-3 randomly 
    /*
    0 -> Salad
    1 -> Soup
    2 -> Sandwich
    3 -> Pizza 
    */
   
   //INPUT VALIDATION 
   
    if(randMeal ==0)
    {
        strcpy(meals, "Salad"); 
        //meals = "Salad"; 
        mealCost = 9.95; 
    }
    else if(randMeal ==1)
    {
        strcpy(meals, "Soup"); 
        //meals = "Soup";
        mealCost = 4.55; 
    }
    else if(randMeal ==2)
    {
        strcpy(meals, "Sandwich"); 
       // meals = "Sandwich";
        mealCost = 13.25;
    }
    else 
    {
        strcpy(meals, "Pizza"); 
        //meals = "Pizza"; 
        mealCost = 22.35; 
    }
    tax = (mealCost/100) * strtod(argv[1], NULL); 
    tip = (mealCost/100) * strtod(argv[2], NULL); 
    //calculating total cost of the meal 
    totalCost = mealCost + tip + tax; 

    //printing the result 
    printf("\nThe meal is: %s", meals); 
    printf("\nThe meal cost is: %f", mealCost); 
    printf("\nTip is: %f", tip);
    printf("\nTax is: %f", tax);
    printf("\nThe total cost is: %f\n", totalCost);

    return 0; 
}
