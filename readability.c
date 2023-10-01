#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
//function declaration
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
//variable declaration
int count = 0, countwords = 1, countsentences = 0;
//get input, calculate, check
int main(void)
{
    //get input from the user
    string txt = get_string("Enter text: ");
    int l = count_letters(txt);
    int w = count_words(txt);
    int s = count_sentences(txt);

    //calculate the number of letters per 100 words
    float L = (100.0 * l) / w;
    float S = (100.0 * s) / w;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    //check grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//count the letters
int count_letters(string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
        else
        {
        }
    }
    return count;
}

//count the words
int count_words(string text)
{
    int len2 = strlen(text);
    for (int j = 1; j < len2; j++)
    {
        if (text[j] == ' ')
        {
            countwords++;
        }
        else
        {

        }
    }
    return countwords;
}

//count the sentences
int count_sentences(string text)
{
    int len3 = strlen(text);
    for (int t = 0; t < len3; t++)
    {
        if (text[t] == '.' || text[t] == '!' || text[t] == '?')
        {
            countsentences++;
        }
        else
        {

        }
    }
    return countsentences;
}