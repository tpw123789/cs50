#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

string change_text(int, string);
string USAGE_ERROR = "Usage: ./caesar key";

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("%s\n", USAGE_ERROR);
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string text = get_string("plaintext: ");
        printf("ciphertext: %s\n", change_text(key, text));
        return 0;
    }
}

string change_text(int key, string text)
{
    key = key % 26;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            if (text[i] + key <= 'z')
            {
                text[i] = text[i] + key;
            }
            else
            {
                text[i] = text[i] + key - 26;
            }
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] + key <= 'Z')
            {
                text[i] = text[i] + key;
            }
            else
            {
                text[i] = text[i] + key - 26;
            }
        }
    }
    return text;
}