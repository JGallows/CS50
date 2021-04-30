// Header files
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Check for key from user
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check for 26 characters
    int lens = strlen(argv[1]);
    if (lens != 26)
    {
        printf("Please input 26 unique letters of the Alphabet \n");
        return 1;
    }

    // Check for alphabetical letters
    for (int i = 0; i < strlen(argv[1]); i++)    
    {
        if (! isalpha(argv[1][i]))
        {
            printf("Please input 26 letters of the Alphabet \n");
            return 1;
        }
    }
    
    // copying argv1 into new array
    char check[26];
    strcpy(check, argv[1]);
    
    // convert lowercase letters to uppercase and add all together
    int j = 0;
    for (int i = 0; i < strlen(check); i++)
    {
        check[i] = toupper(check[i]);
        j = j + (check[i]);
    }
    
    // Check for duplicate characters by checking if total of uppercase = the sum of all alphabetical ascii values
    if (j != 2015)
    {
        printf("Please input 26 letters of the Alph \n");
        return 1;
    }
    
    printf("Success \n");
    
    // Get plaintext input from user
    string plaintext = get_string("Plaintext: ");
    
    
    // Print cypher
    printf("ciphertext: ");
    
    // Convert each character into corresponding cipher and output
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int l = plaintext[i] - 'A';
            char cyphertext = argv[1][l];
            
            if (isupper(argv[1][l]))
            {
                printf("%c", cyphertext);
            }
            else 
            {
                printf("%c", (toupper(cyphertext)));
            }
        }    
        else if (islower(plaintext[i]))
        {
            int f = plaintext[i] - 'a';
            char cyphertext2 = argv[1][f];
            
            if (islower(argv[1][f]))
            {
                printf("%c", cyphertext2);    
            }
            else
            {
                printf("%c", (tolower(cyphertext2)));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    return 0;
}


