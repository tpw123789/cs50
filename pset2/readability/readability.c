#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_func(char, string);
int calulate_grade(int, int, int);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_func('l', text);
    int words = count_func('w', text);
    int sentences = count_func('s', text);
    int ans = calulate_grade(letters, words, sentences);
    if (ans < 16 && ans >= 1)
    {
        printf("Grade %i\n", ans);
    }
    else if (ans < 1)
    {
        printf("%s\n", "Before Grade 1");
    }
    else
    {
        printf("%s\n", "Grade 16+");
    }
}

int count_func(char target, string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int n = strlen(text);
    if (n > 0)
    {
        for (int i  = 0; i < n; i++)
        {
            char letter = toupper(text[i]);
            if (letter <= 'Z' && letter >= 'A')
            {
                letters++;
            }
            else if (letter == ' ')
            {
                words++;
            }
            else if (letter == '.' || letter == '?' || letter == '!')
            {
                sentences++;
            }
        }
        if (target == 'w')
        {
            return words + 1;
        }
        if (target == 'l')
        {
            return letters;
        }
        if (target == 's')
        {
            return sentences;
        }
    }
    return 0;
}


int calulate_grade(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

