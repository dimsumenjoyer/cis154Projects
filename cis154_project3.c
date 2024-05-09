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
void writeCipherText(char* fileName, char* text, int offset, int cardinality);
int encryptText(void);
int decryptText(void);
void displayMenu(void);

void makePlainText(void);

typedef struct 
{
    char fileName[TEXT_BUFFER_SIZE];
    char plainText[TEXT_BUFFER_SIZE];
    char encryptedFileName[TEXT_BUFFER_SIZE];
    char decryptedFileName[TEXT_BUFFER_SIZE];
    int offset, characterCount;

} fileInfo;


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
        puts("NECC File Encryption & Decryption Program:\nPlease select an option:\n0. Create file\n1. Encrypt File\n2. Decrypt File\n3. Exit\nEnter your choice: ");
        scanf("%d", &userInput);

        switch(userInput)
        {
            case 0:
                puts("Create file");
                makePlainText();
                break;

            case 1:
                puts("Encrypt File");
                encryptText();
                break; 
            case 2:
                puts("Decrypt File");
                decryptText();
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

void makePlainText(void)
{
    char fileNameWithoutExtension[TEXT_BUFFER_SIZE];
    const char* fileExtension = ".md";
    char plainText[TEXT_BUFFER_SIZE];
    puts("Plain Text File Name: ");
    scanf("%s", fileNameWithoutExtension);
    
    if (strlen(fileNameWithoutExtension) >= TEXT_BUFFER_SIZE - strlen(fileExtension) - 1) 
    {
        puts("Error: Filename too long.");
        return;
    }
    strcpy(fileNameWithoutExtension, fileNameWithoutExtension);
    strcat(fileNameWithoutExtension, fileExtension);
    FILE* file = fopen(fileNameWithoutExtension, "w");

    if (file == NULL) 
    {
        puts("Error opening file.");
        return;
    }
    puts("Write stuff into file: ");
    scanf("%s", plainText);
    fwrite(plainText, sizeof(char), strlen(plainText), file);
    fclose(file);
}

int readPlainText(char* buffer, char* fileName)
{
    FILE* file = fopen(fileName, "r");
    char characterInFile;
    int characterCount = 0;

    if (file != NULL)
    {
        while ((characterInFile = fgetc(file)) != EOF)
        {
            buffer[characterCount] = characterInFile;
            characterCount++;
        }
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

char* readCipherText(char* fileName, int *offset, int *cardinality)
{
    FILE* file = fopen(fileName, "rb");
    if (file == NULL)
    {
        puts("Error: Unable to open file.");
        return NULL;
    }
    const char* fileExtension = ".bin";
    int fileNameLength = strlen(fileName);
    int extensionLength = strlen(fileExtension);

    if (fileNameLength < extensionLength ||
        strcmp(fileName + fileNameLength - extensionLength, fileExtension) != 0)
    {
        fclose(file);
        puts("Error: File does not have the correct extension.");
        return NULL;
    }
    char* encryptedData = malloc(TEXT_BUFFER_SIZE * sizeof(char));
    if (encryptedData == NULL)
    {
        fclose(file);
        puts("Error: Memory allocation failed.");
        return NULL;
    }

    *cardinality = fread(encryptedData, sizeof(char), TEXT_BUFFER_SIZE, file);
    *offset = encryptedData[4];
    
    fclose(file);
    return encryptedData;
}

void writeCipherText(char* fileName, char* text, int offset, int cardinality)
{
    FILE* file = fopen(fileName, "wb"); // -> writes to binary file

    // necc offset cardinality text
    char textArray[TEXT_BUFFER_SIZE + 4] = "NECC";
    textArray[4] = offset;
    textArray[5] = cardinality;
    strncat(textArray, text, TEXT_BUFFER_SIZE);

    if (file != NULL)
    {
        fwrite(textArray, sizeof(char), TEXT_BUFFER_SIZE, file);
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
    char* fileExtension = ".md";
    int cardinality;

    puts("Enter the name of the file you want to encrypt: ");
    scanf("%s", fileName);

    strcat(fileName, fileExtension);
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
        writeCipherText(encryptedFileName, plainText, offset, characterCount);
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
    char fileName[TEXT_BUFFER_SIZE];
    char decryptedFileName[TEXT_BUFFER_SIZE];
    char plainText[TEXT_BUFFER_SIZE];
    int offset = 0;
    int cardinality = TEXT_BUFFER_SIZE;

    puts("Enter the name of the file you want to decrypt: ");
    scanf("%s", fileName);
    puts("Enter the desired name for the decrypted file: ");
    scanf("%s", decryptedFileName);
    puts("Offset for Decryption (Type an integer): ");
    scanf("%d", &offset);

    FILE* file = fopen(fileName, "rb");
    if (file == NULL)
    {
        puts("Error: Unable to open file for decryption."); // VSCode showx error here, but not below -> makes pointer from integer without cast
        return -1;
    }

    char arrayText[TEXT_BUFFER_SIZE];
    fread(arrayText, sizeof(char), TEXT_BUFFER_SIZE, file);
    fclose(file);

    offset = arrayText[4];
    cardinality = arrayText[5];

    char* cipherText = readCipherText(fileName, &offset, &cardinality); // *makes pointer from integer without cast*
    if (cipherText != NULL && cardinality > 0)
    {
        int characterCount = cipherText[5];
        for (int i = 0; i < characterCount; i++)
        {
            if (isalpha(cipherText[i]))
            {
                if (isupper(cipherText[i]))
                {
                    cipherText[i] = ((cipherText[i] - 'A' - offset + 26) % 26) + 'A';
                }
                else if (islower(cipherText[i]))
                {
                    cipherText[i] = ((cipherText[i] - 'a' - offset + 26) % 26) + 'a';
                }
            }
        }

        writeCipherText(decryptedFileName, cipherText, offset, characterCount);
        printf("File '%s' has been decrypted and saved as '%s'.\n", fileName, decryptedFileName);
        printf("Decrypted Text:\n%s\n", cipherText);
        free(cipherText);
        return 0;
    }
    else
    {
        puts("Decryption failed due to read error or invalid file format.");
        return -1;
    }
}