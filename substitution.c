#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//get the key
string KEY;
int main(int argc, string key[]);
int encrypt(void);
int main(int argc, string key[])
{
    //error if a key is not provided, or too many comand line arguments are provided
    if (argc != 2)
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }
    //no more or less than 26 chars
    else if (strlen(key[1]) != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }
    //check for non-alphabetic or repeated chars
    else
    {
        KEY = key[1];
        for (int i = 0; i < strlen(key[1]); i++)
        {
            char keychar = key[1][i];
            for (int j = 0; j < strlen(key[1]); j++)
            {
                char keychar2 = key[1][j];
                if ((i != j) && (keychar == keychar2))
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
                else if (!isalpha(keychar2))
                {
                    printf("only characters are valid\n");
                    return 1;
                }
                else
                {
                }
            }
        }
        encrypt();
    }
}
//assign key characters to alphabetic characters
int encrypt(void)
{
    string plain_text = get_string("Plain text: ");
    int length = strlen(plain_text);
    //assigning
    printf("ciphertext: ");
    for (int j = 0; j < length; j++)
    {
        //if a character in plain text is lower we convert the apropriate key char to lower as well
        if (islower(plain_text[j]))
        {
            int cipher = plain_text[j] - 97;
            printf("%c", tolower(KEY[cipher]));
        }
        //if a character in plain text is upper we convert the apropriate key char to upper as well
        else if (isupper(plain_text[j]))
        {
            int cipher = plain_text[j] - 65;
            printf("%c", toupper(KEY[cipher]));
        }
        else
        {
            //if the char is punctuation or space, print the same plain text character
            printf("%c", plain_text[j]);
        }
    }
    printf("\n");
    return 0;
}