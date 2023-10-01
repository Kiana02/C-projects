#include <stdio.h>
#include <cs50.h>
#include<string.h>
int main()
{
    //get input from the user
    long cnum = get_long("Enter: ");
    //extract every other digit from last to first
    int c0 = ((cnum % 100) / 10);
    int c1 = ((cnum % 10000) / 1000);
    int c2 = ((cnum % 1000000) / 100000);
    int c3 = ((cnum % 100000000) / 10000000);
    int c4 = ((cnum % 10000000000) / 1000000000);
    int c5 = ((cnum % 1000000000000) / 100000000000);
    int c6 = ((cnum % 100000000000000) / 10000000000000);
    int c7 = ((cnum % 10000000000000000) / 1000000000000000);
    //extract whatever digit is left
    int b0 = cnum % 10;
    int b1 = (cnum % 1000) / 100;
    int b2 = (cnum % 100000) / 10000;
    int b3 = (cnum % 10000000) / 1000000;
    int b4 = (cnum % 1000000000) / 100000000;
    int b5 = (cnum % 100000000000) / 10000000000;
    int b6 = (cnum % 10000000000000) / 1000000000000;
    int b7 = (cnum % 1000000000000000) / 100000000000000;
    //calculation
    int everyother = (c0 * 2) % 10 + (c1 * 2) % 10 + (c2 * 2) % 10 + (c3 * 2) % 10 + (c4 * 2) % 10 + (c5 * 2) % 10 + (c6 * 2) % 10 +
                     (c7 * 2) % 10 + (((c0 * 2) % 100) / 10) + (((c1 * 2) % 100) / 10) + (((c2 * 2) % 100) / 10) + (((c3 * 2) % 100) / 10) +
                     (((c4 * 2) % 100) / 10) + (((c5 * 2) % 100) / 10) + (((c6 * 2) % 100) / 10) + (((c7 * 2) % 100) / 10);
    int other = b0 + b1 + b2 + b3 + b4 + b5 + b6 + b7;
    //calculate the checksum
    int checksum = (everyother + other);
    int val = checksum % 10;
    //check the conditions
    if (val == 0)
    {
        if (b7 == 3 && (c6 == 4 || c6 == 7))
        {
            printf("AMEX\n");
        }
        else if (b6 == 4 || c7 == 4)
        {
            printf("VISA\n");
        }
        else if (c7 == 5 && (b7 == 1 || b7 == 2 || b7 == 3 || b7 == 4 || b7 == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}