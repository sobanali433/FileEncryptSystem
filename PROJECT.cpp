#include <stdio.h>
#include <string.h>

void encryptFile(char fileName[])
{
    FILE *input, *output;
    char ch;
    int key = 10;

    input = fopen(fileName, "r");

    if (input == NULL)
    {
        printf("File not found!\n");
        return;
    }

    output = fopen("encrypted.txt", "w");

    while ((ch = fgetc(input)) != EOF)
    {
        ch = ch ^ key;
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");
}

void decryptFile(char fileName[])
{
    FILE *input, *output;
    char ch;
    int key = 10;

    input = fopen(fileName, "r");

    if (input == NULL)
    {
        printf("File not found!\n");
        return;
    }

    output = fopen("decrypted.txt", "w");
    output = fopen("C:\\Users\\SobanAli\\Desktop\\encrypted.txt", "w");


    while ((ch = fgetc(input)) != EOF)
    {
        ch = ch ^ key;
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);

    printf("File decrypted successfully!\n");
}

void readFile(char fileName[])
{
    FILE *file;
    char ch;

    file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\n----- File Content -----\n");

    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n------------------------\n");

    fclose(file);
}

int main()
{
    char username[50];
    char password[50];

    char fileName[100];
    int choice;

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        printf("\nLogin Successful!\n");

        printf("\n1. Encrypt File");
        printf("\n2. Decrypt File");
        printf("\n3. Read File");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter file name: ");
                scanf("%99s", fileName);

                encryptFile(fileName);
                break;

            case 2:

                printf("Enter file name: ");
                scanf("%99s", fileName);

                decryptFile(fileName);
                break;

            case 3:

                printf("Enter file name: ");
                scanf("%99s", fileName);

                readFile(fileName);
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    else
    {
        printf("Invalid Username or Password!\n");
    }

    return 0;
}