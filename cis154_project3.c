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

int readPlainText(char* buffer, char* fileName);
int* readCipherText (char* fileName, int *offSet, int *cardinality);
void writeCipherText(char* fileName, char* text, int offSet, int cardinality);
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
    int userInput;
    while (!done)
    {
        puts("Welcome to the NECC File Encryption and Decryption Program!\nPlease select an option:\n1. Encrypt File\n2. Decrypt File\n3. Exit\nEnter your choice: ");
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1: puts("Encrypt File"); break; case 2: puts("Decrypt File"); break; 
            case 3: puts("Program Terminated. Thank you for using the NECC File Encryption and Decryption Program!"); done = true; break;
            default: puts("Error: Invalid Input.\n");
        }
    }
}

int readPlainText(char* buffer, char* fileName)
{
    FILE *file = fopen(fileName, "r"); // r -> read file
    if (file != NULL)
    {
        fread(buffer, sizeof(char), TEXT_BUFFER_SIZE - 1, file);
        buffer[TEXT_BUFFER_SIZE - 1] = '\0';
        fclose(file);
        return 0;
    }
    puts("Plain Text File Error");
    fclose(file);
    return -1;
}

int* readCipherText(char* fileName, int *offSet, int *cardinality)
{
    FILE *file = fopen(fileName, "rb"); // rb -> read binary file
    if (file != NULL)
    {
        char* encryptedTextArray = malloc(sizeof(char) * TEXT_BUFFER_SIZE);
        fclose(file);
        return encryptedTextArray;
    }
    puts("Cipher Text File Error");
    fclose(file);
}

void writeCipherText(char* fileName, char* text, int offSet, int cardinality)
{
    FILE *file = fopen(fileName, "wb"); // wb -> write to binary file
    if (file != NULL)
    {
        puts("Cipher Text File Error");
        fclose(file);
    }
    puts("Cipher Text File Error");
    fclose(file);
}

int encryptText(void)
{
    char* fileName;
    char* encryptedFileName;
    int offset;
    int characterCount;
    char plainText[TEXT_BUFFER_SIZE];
    puts("Enter the name of the file you want to encrypt: ");
    scanf("%s", &fileName);
    puts("Enter the desired name for the encrypted file: ");
    scanf("%s", &encryptedFileName);
    puts("Offset for Encryption (Type an integer): ");
    scanf("%d", offset);
    characterCount = readPlainText(plainText, fileName);
    for (int i = 0; i < characterCount; i++)
    {
        if (isAlpha(plainText[i])) 
        {
            plainText[i] = ((plainText[i] - 'A' + offset) % 26) + 'A';
        }
        else
        {
            puts("Your code is probably fucked.");
        }
    }
    char* fileNameWithExtension = strcat(fileName, ".necc");
    printf("File '%s' has been created & encrypted.", fileName);
    return 0;
}

int decryptText(void)
{
    

}