/*
Victor Van
4/13/2024, Due: 4/13/2024
C - Professor Penta
Project 2
*/

I think that this project would be more interesting if I already knew how to return arrays. 
We're currently learning about pointers. This would've been a good opportunity on being evaluated on passing by reference & passing by value.

while (userInput != 0 && userInput == 1) 
    {
        iteration++;
        if (iteration != 1)
        {
            clearScreen();
        }
    }

This chunk of code ensures that every time the user wants to replay the game, the screen is "refreshed" but prevents 50 lines from being printed on the first run.
However, there probably are better ways to write this. I think I overcomplicated my code a bit.
My main function works, but is messier than what I would like.

int randomDecider(void)
{
    int randomNumber = rand() % 2;
    return randomNumber;
}

I am still confused to why the syntax of rand() is like this. I would've expected it to be something like rand(0,1);.

The generateRandomBurger function generates a random burger. if randomDecider is true, then it stores the current iteration of the for loop into the array (a2).
It also keeps track of the number of ingredients if the condition is met before being returned.

The functions buildBurger and printBurger are self-explanatory.

Boolean functions are really useful to help simplify code.

I had the most trouble with the compareBurger function since I have had difficulty understanding how to effectively use arrays. 
The function uses histrogramFunction to modify the histrogram array to keep track of a1 (the user generated array) and a2 (the randomly generated array), and then is used to check if they match.
It returns 0 if false, otherwise it's true so it returns 1.

Professor Penta helped me write histrogramFunction on the my homework assignments, which I copied and pasted for this project.
For each element of array, the histrogram array iterates and keeps track of the numbers that are inside the array.
However, histrogram[array[i]]++; can be confusing.

The calculateTotals function is self-explanatory, but it consists of a number of helper functions to maintain readability.
Although I wonder how this function could further be simplified.
These lines calculate the cost of the burger.
double score = 0;
double baseCostOfBurger = 6.99; 
score += baseCostOfBurger;
calculateCondiments(burgerOrder, cardinalityOfArray, score);
calculateVeggies(burgerOrder, cardinalityOfArray, score);
calculateCheese(burgerOrder, cardinalityOfArray, score);
If the order is incorrect, then the cost of the burger will just be (int) $2.
The specials have their own conditions, so I thought that it would be easier to organize the code by creating functions for each of them.
These function are called accountly to their respective ingredients, and are effectively boolean functions.

The playRound function is self-explanatory.
