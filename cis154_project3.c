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

int readPlainText(char* buffer, char* fileName);
char* readCipherText (char* fileName, int *offSet, int *cardinality);
void writeCipherText(char* fileName, char* text, int cardinality);
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
        puts("NECC File Encryption & Decryption Program:\nPlease select an option:\n1. Encrypt File\n2. Decrypt File\n3. Exit\nEnter your choice: ");
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1:
                puts("Encrypt File");
                encryptText();
                break; 
            case 2:
                puts("Decrypt File");
                //decryptText();
                break; 
            case 3:
                puts("NECC File Encryption & Decryption Program Terminated."); 
                done = true;
                break;
            default:
                puts("Error: Invalid Input.\n");
        }
    }
}

int readPlainText(char* buffer, char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file != NULL)
    {
        //int characterCount = fread(buffer, sizeof(char), TEXT_BUFFER_SIZE - 1, file);
        
        buffer[characterCount] = '\0';
        fclose(file);
        return characterCount;
    }
    else
    {
        puts("Plain Text File Error");
        return -1;
    }
}

char* readCipherText(char* filename, int *offset, int *cardinality)
{
    return;
}

void writeCipherText(char* fileName, char* text, int cardinality)
{
    FILE* file = fopen(fileName, "w");
    if (file != NULL)
    {
        fwrite(text, sizeof(char), cardinality, file);
        fclose(file);
    }
    else
    {
        puts("Cipher Text File Error");
    }
}

int encryptText(void)
{
    char fileName[TEXT_BUFFER_SIZE];
    char encryptedFileName[TEXT_BUFFER_SIZE];
    char plainText[TEXT_BUFFER_SIZE];
    int offset = 0;

    puts("Enter the name of the file you want to encrypt: ");
    scanf("%s", fileName);
    puts("Enter the desired name for the encrypted file: ");
    scanf("%s", encryptedFileName);
    puts("Offset for Encryption (Type an integer): ");
    scanf("%d", &offset);

    int characterCount = readPlainText(plainText, fileName);
    if (characterCount > 0)
    {        
        for (int i = 0; i < characterCount; i++)
        {
            if (isalpha(plainText[i]))
            {
                if (isupper(plainText[i]))
                {
                    plainText[i] = ((plainText[i] - 'A' + offset) % 26) + 'A';
                }
                else if (islower(plainText[i]))
                {
                    plainText[i] = ((plainText[i] - 'a' + offset) % 26) + 'a';
                }
            }
        }

        writeCipherText(encryptedFileName, plainText, characterCount);
        printf("File '%s' has been created & encrypted.\n", encryptedFileName);
        return 0;
    }
    else
    {
        puts("Encryption failed due to read error.");
        return -1;
    }
}

int decryptText(void)
{

}