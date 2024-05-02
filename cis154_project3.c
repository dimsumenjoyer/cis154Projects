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

typedef struct
{
    char* fileName, text, buffer;
    int* offSet, cardinality;
    int offset, cardinality;
} infoArray_File;

#define TEXT_BUFFER_SIZE 10000

void readPlainText(char* buffer, char* fileName);
void readCipherText (char* fileName, int *offSet, int *cardinality);
void writeCipherText(char* fileName, char* text, int offSet, int cardinality);
int encryptText(void);
int decryptText(void);
void displayMenu(void);
void menuInput(int userInput);
char* concatenateString(char* s1);

int main(void)
{
    displayMenu();
    return 0;
}

void displayMenu(void)
{
    bool done = false;
    int userInput;
    while (!done)
    {
        puts("Welcome to the NECC File Encryption and Decryption Program!\nPlease select an option:\n1. Encrypt File\n2. Decrypt File\n3. Exit\nEnter your choice: ");
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1: puts("Encrypt File"); break; case 2: puts("Decrypt File"); break; 
            case 2: puts("Program Terminated. Thank you for using the NECC File Encryption and Decryption Program!"); done = true; break;
            default: puts("Error: Invalid Input.\n");
        }
    }
    menuInput(userInput);
}

void menuInput(int userInput)
{
    char* userInputedFileName;
    switch(userInput)
    {
        case 1: puts("Please enter the name of the plaintext file you wish to encrypt (no extension): ");
        scanf("%s", &userInputedFileName);
        char* fileName = concatenateString(userInputedFileName); //fileName.necc
        break;// encrypt file FILE *file = fopen("numberFile.md", "w");

        case 2:
        break;
    }
}

void readPlainText(char* buffer, char* fileName)
{
    FILE *file = fopen(fileName, "r");
}

void readCipherText(char* fileName, int *offSet, int *cardinality)
{
    
}

void writeCipherText(char* fileName, char* text, int offSet, int cardinality)
{
}

int encryptText(void)
{
    \*
    int cardinalityOfStr = strlen(str);
    for (int i = 0; i < cardinalityOfStr; i++)
    {
        if (isupper(str[i])) 
        {
            str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
        } 
        else if (islower(str[i])) 
        {
            str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
        }
        else
        {
            puts("Your code is fucked.");
        }
        printf("%c\n", str[i]);
    }
    \\decoderCaptainCrunch(str);
    *\
}

int decryptText(void)
{

}

char* concatenateString(char* s1)
{
    char* s2 = ".necc";
    int cardinality = strlen(s1) + strlen(s2);
    char* fileName = (char*)malloc(cardinality);
    int currentIndex = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        fileName[currentIndex] = s1[i];
        currentIndex++;
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        fileName[currentIndex] = s2[i];
        currentIndex++;
    }
    fileName[currentIndex] = '\0';
    return fileName;
}
