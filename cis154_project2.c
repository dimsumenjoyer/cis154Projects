/*
Victor Van
3/24/2024, Due: 4/13/2024
C - Professor Penta
Project 2
*/

#include <stdio.h>
#include <time.h>
#include <string.h>

void clearScreen(void);
int randomDecider(void);
int* generateRandomBurger(int* randomBurgerOrder, int* count);
int buildBurger(int* array, int cardinalityOfArray);
void printBurger(int* burgerOrder, int cardinalityOfArray);
int compareBurger(int* a1, int* a2, int a1Cardinality, int a2Cardinality);
int calculateTools(int* a1, int a1Cardinality, int orderCorrectOrIncorrect);
int playRound(void);

int main(void) 
{
    srand(time(NULL));
    int totalScore = 0;
    int userInput;
    int iteration = 0;
    printf("Want to play? (0 v 1): \n");
    scanf("%d", &userInput);
    while (userInput != 0 && userInput == 1) 
    {
        if (iteration != 0)
        {
            clearScreen();
            iteration++;
        }
        totalScore += playRound();
        printf("Total score: %d\n", totalScore);
        printf("Play again? (0 v 1): \n");
        scanf("%d", &userInput);
    }
    printf("Game over. Final score: %d\n", totalScore);
    return 0;
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

int* generateRandomBurger(int* randomBurgerOrder, int* count)
{
    int ingredientsOfBurger[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cardinalityOfBurger = sizeof(ingredientsOfBurger) / sizeof(ingredientsOfBurger[0]);
    *count = 0;
    for (int i = 0; i < cardinalityOfBurger; i++)
    {
        if (randomDecider() == 0)
        {
            continue;
        }
        randomBurgerOrder[*count] = ingredientsOfBurger[i];
        (*count)++;
    }
    return count;
}

int buildBurger(int* array, int cardinalityOfArray) 
{
    for (int i = 0; i < cardinalityOfArray; i++) 
    {
        int userOrderInput;
        printf("Pick your ingredients of your burger (0 - 10): \n");
        scanf("%d", &userOrderInput);
        if (userOrderInput < 0 || userOrderInput > 10) 
        {
            printf("Error: Invalid Order. Enter a number between 0 - 10\n");
            i--;
        } 
        else 
        {
            array[i] = userOrderInput;
        }
    }
    return cardinalityOfArray;
}

void printBurger(int* burgerOrder, int cardinalityOfArray)
{
    for (int i = 0; i < cardinalityOfArray; i++)
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
            default: puts("If you're reading this, then your code is fucked.");
        }
    }
}


int compareBurger(int* a1, int* a2, int a1Cardinality, int a2Cardinality) 
{
    int counts[11] = {0};
    for (int i = 0; i < a1Cardinality; i++) 
    {
        counts[a1[i]]++;
    }
    for (int i = 0; i < a2Cardinality; i++) 
    {
        if (--counts[a2[i]] < 0) 
        {
            return 0;
        }
    }
    return 1;
}

int calculateTotals(int* burgerOrder, int cardinalityOfArray, int orderCorrectOrIncorrect) 
{
    int score = 0;
    if (orderCorrectOrIncorrect) 
    {
        score++;
    }
    return score;
}

int playRound(void)
{
    int randomBurgerOrder[11];
    int count;
    generateRandomBurger(randomBurgerOrder, &count);
    int userBurgerOrder[11];
    buildBurger(userBurgerOrder, 11);
    int orderCorrectOrIncorrect = compareBurger(randomBurgerOrder, userBurgerOrder, count, 11);
    int roundScore = calculateTotals(userBurgerOrder, 11, orderCorrectOrIncorrect);
    return roundScore;
}