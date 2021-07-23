#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_number(long);
int check_number(long);
string card_type(long);
string s_invalid = "INVALID";


int main(void)
{
    // America Express: 15 diigits, start with 34 or 37
    // MasterCard: 16 digits, start with 51~55
    // Visa: 13 or 16 digits, start with 4
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    // printf("Check number: %d\n", check_number(number));
    
    if (check_number(number))
    {
        printf("%s\n", card_type(number));
    }
    else
    {
        printf("%s\n", s_invalid);
    }
    
}


int count_number(long number)
{
    int count = 0;
    while (number >= 1)
    {
        number /= 10;
        count++;
    }
    
    return count;
}


int check_number(long number)
{
    int sum = 0;
    while (number >= 1)
    {
        sum += number % 10;
        number /= 10;
        if ((number % 10) * 2 >= 10)
        {
            int temp = (number % 10) * 2;
            sum += temp % 10;
            sum += temp / 10;
        }
        else
        {
            sum += (number % 10) * 2;
        }
        number /= 10;
    }
    
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


string card_type(long number)
{
    int count = count_number(number);
    // printf("Number count: %d\n", count);
    // first two numbers
    while (number >= 100)
    {
        number /= 10;
    }
    // printf("First two number: %li\n", number);
    // 15 digits and start with 34 or 37 
    if (count == 15)
    {
        if (number == 34 || number == 37)
        {
            return "AMEX";
        }
    }
    // 16 digits and start with 4 or 51 ~ 55   
    else if (count == 16)
    {
        if (number / 10 == 4)
        {
            return "VISA";
        }
        if (number >= 51 && number <= 55)
        {
            return "MASTERCARD";
        }
    }
    // 13 digits and start with 4
    else if (count == 13)
    {
        if (number / 10 == 4)
        {
            return "VISA";
        }
    }
    
    return s_invalid;
}





