/*
Victor Van
4/14/2024, Due: 5/4/2024
C - Professor Penta
Project 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TEXT_BUFFER_SIZE 10000

void readPlainText(char* buffer, char* fileName);
void writeCipherText(char* fileName, char* text, int offSet, int cardionality);
int encryptText(void);
int decryptText(void);
void displayMenu(void);

int main(void)
{
    displayMenu();
    return 0;
}

void displayMenu(void)
{
    bool done = false;
    while (!done)
    {
        int userInput;
        puts("Welcome to the NECC File Encryption and Decryption Program!\nPlease select an option:\n1. Encrypt File\n2. Decrypt File\n3. Exit\nEnter your choice: ");
        scanf("%d", &userInput);
        if (userInput == 1)
        {
            puts("Encrypt file");
        }
        else if (userInput == 2)
        {
            puts("Decrypt file");
        }
        else if (userInput == 3)
        {
            puts("Program Terminated. Thank you for using the NECC File Encryption and Decryption Program!");
            done = true;
        }
        else
        {
            puts("Error: Invalid Input.\n");
        }
    }
}