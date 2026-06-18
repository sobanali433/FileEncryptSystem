#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USERNAME "system"
#define PASSWORD "security"
#define XOR_KEY 123

void login();
void encryptFile();
void decryptFile();
void readFile();

int main()
{
    int choice;

    login();

    while (1)
    {
        printf("\n==============================\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Read File\n");
        printf("4. Exit\n");
        printf("==============================\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                encryptFile();
                break;

            case 2:
                decryptFile();
                break;

            case 3:
                readFile();
                break;

            case 4:
                printf("Good Bye!\n");
                exit(0);

            default:
                printf("Invalid Num!\n");
        }
    }

    return 0;
}

void login()
{
    char username[50];
    char password[50];
    int attempts = 0;

    while (1)
    {
        printf("\n NOTE: After Three Wrong UN & PASS ACCOUNT SUSPENDED FOR TWO MINS.\n");

        printf("\n===== FILE ENC & DEC SYSTEM =====\n");
        printf("\n PLEASE LOGIN USERNAME & PASSWORD \n");
    
		printf("please enter Username: ");
        scanf("%s", username);

        printf("please enter Password: ");
        scanf("%s", password);

        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0)
        {
            printf("\nLogin Successfull!\n");
            return;
        }

        attempts++;

        if (attempts >= 3)
        {
            printf("\nToo many failed attempts!\n");
            printf("Account locked for 2mins.\n");

            time_t start = time(NULL);

            while (difftime(time(NULL), start) < 120)
            {
                //working
            }

            attempts = 0;

            printf("\nAccount Unlocked.\n");
        }
        else
        {
            printf("Wrong Credentials!\n");
            printf("Attempts Left: %d\n", 3 - attempts);
        }
    }
}

void encryptFile()
{
    char filename[1000];
    char outputFile[1000];

    FILE *fp, *enc;

    printf("Enter File Name: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    sprintf(outputFile, "encrypted_%s", filename);

    enc = fopen(outputFile, "wb");

    if (enc == NULL)
    {
        printf("Unable to create encrypted file.\n");
        fclose(fp);
        return;
    }

    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(ch ^ XOR_KEY, enc);
    }
		
		fclose(fp);
    fclose(enc);

    printf("Encrypted File Saved As: %s\n", outputFile);
}

void decryptFile()
{
    char filename[1000];
    char outputFile[1000];

    FILE *fp, *dec;

    printf("Enter decrypted File Name: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    sprintf(outputFile, "decrypted_%s", filename);

    dec = fopen(outputFile, "wb");

    if (dec == NULL)
    {
        printf("Unable to create decrypted file.\n");
        fclose(fp);
        return;
    }

    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(ch ^ XOR_KEY, dec);
    }

    fclose(fp);
    fclose(dec);

    printf("Decrypted File Saved As: %s\n", outputFile);
}

void readFile()
{
    char filename[1000];

    FILE *fp;

    printf("Enter File Name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }
    
    printf("\n === FILE =====\n");
    
    char ch;
    while((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}
	
	printf("\n");
	fclose(fp);
}