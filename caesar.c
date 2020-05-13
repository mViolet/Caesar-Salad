#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
    int counter = 0;
    string inputString = argv[1];
    //check to make sure
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) != 0) 
            {
                //anything here will execute once only if the char is a digit
                counter++;
                
                //checks if the counter above matches string length. 
                //This is so that the code only runs if the key is in digits
                
                if (counter == strlen(argv[1]))
                {
                    //integer to store command line argument key
                    int key = atoi(argv[1]);
                    //following prompt holds user's string or secret message in plaintext
                    string input = get_string("plaintext: ");
                    //integer to keep track of string length
                    int strSize = strlen(input);
                    
                    printf("ciphertext: ");
                    
                    //This loop checks if each character is Upper, Lower, or some other character, and then applies the ((input + key)-(start in ASCII chart)) % 26... formula to make sure the characters wrap around correctly, prints the character, & moves on.
                    for (int g = 0; g < strSize; g++) 
                    {
                        if (isupper(input[g])) 
                        {
                            printf("%c", (((input[g] + key) - 65) % 26) + 65);
                        }
                        else if (islower(input[g])) 
                        {
                            printf("%c", (((input[g] + key) - 97) % 26) + 97);
                        }
                        else 
                        {
                            printf("%c", input[g]);
                        }
                    }
                    // Space for readability
                    printf("\n");
                    
                }
                
            } 
            else 
            {
                //Returns with 1 if command line argument is not a digit
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        
    } 
    else
    {
        //Returns with 1 if a command line argument is not provided
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


