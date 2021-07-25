#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

string change_text(string, string);
int check_key(string);
string USAGE_ERROR = "Usage: ./substitution  key";
string KEY_ERROR = "Key must contain 26 characters.";

int main(int argc, string argv[])
{
    int a[26];
    if (argc < 2)
    {
        printf("%s\n", USAGE_ERROR);
        return 1;
    }
    else
    {
        if (strlen(argv[1]) != 26 || check_key(argv[1]) == 1)
        {
            printf("%s\n", KEY_ERROR);
            return 1;
        }
        string text = get_string("plaintext: ");
        printf("ciphertext: %s\n", change_text(argv[1], text));
        return 0;
    }
}

string change_text(string key, string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int index = text[i] - 97;
            text[i] = tolower(key[index]);
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int index = text[i] - 65;
            text[i] = toupper(key[index]);
        }
    }
    return text;
}


int check_key(string key)
{
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;   
    }
    
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return 1;
        }
        int index = toupper(key[i]) - 65;
        count[index]++;
        if (count[index] > 1)
        {
            return 1;
        }
    }
    return 0;
}