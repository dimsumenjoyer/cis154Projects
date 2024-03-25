/*
Victor Van
3/24/2024, Due: 4/13/2024
C - Professor Penta
Project 2
*/

#include <stdio.h>
#include <time.h>

void clearScreen(void);
int randomDecider(void);
int generateRandomBurger(int randomBurgerOrder);
int buildBurger(int array[], int magnitudeOfArray);
void printBurger(int burgerOrder[], int magnitudeOfArray);
int compareBurger(int a1[], int a2[], int a1Magnitude, int a2Magnitude);
int calculateTools(int a1[], int a1Magnitude, int orderCorrectOrIncorrect);
int playRound(void);

int main(void)
{
    srand(time(NULL));
    int number = randomDecider();
    printf("%d\n", number);
}

void clearScreen(void)
{
    for (int i = 50; i > 0; i--)
    {
        puts("");
    }
}

int randomDecider(void)
{
    int randomNumber = rand() % 2;
    return randomNumber;
}

int generateRandomBurger(int randomBurgerOrder)
{
    int ingredientsOfBurger[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int magnitudeOfArray = sizeof(ingredientsOfBurger) / sizeof(ingredientsOfBurger[0]);
}

int buildBurger(int array[], int magnitudeOfArray)
{
    for (int i = 0; i < magnitudeOfArray; i++)
    {
        int userOrderInput;
        puts("Enter integers between 0 - 10 to pick your ingredients of your burger:");
        int userOrder = scanf("%d", &userOrderInput);
        puts("");
        if (userOrder < 0 || userOrder > 10)
        {
            puts("Error: Invalid Order. Enter a number between 0 - 10");
        }
        else
        {
            array[i] = userOrder;
        }
    }
    return magnitudeOfArray;
}

void printBurger(int burgerOrder[], int magnitudeOfArray)
{
    for (int i = 0; i < magnitudeOfArray; i++)
    {
        switch (burgerOrder[i])
        {
            case 0: puts("Top Bun"); break;
            case 1: puts("Mayo"); break;
            case 2: puts("Mustard"); break;
            case 3: puts("Ketchup"); break;
            case 4: puts("Tomato"); break;
            case 5: puts("Onion"); break;
            case 6: puts("Lettuce"); break;
            case 7: puts("Pickle"); break;
            case 8: puts("Cheese"); break;
            case 9: puts("Patty"); break;
            case 10: puts("Bottom Bun"); break;
            default: puts("If you're reading this, then this code is bugged.");
        }
    }
    puts("");
}


int compareBurger(int a1[], int a2[], int a1Magnitude, int a2Magnitude)
{

}

int calculateTools(int a1[], int a1Magnitude, int orderCorrectOrIncorrect)
{

}

int playRound(void)
{
    int roundScore = 0;
    return roundScore;
}