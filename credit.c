#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int Num_Length (long Card_Num);
bool Peter_Luhn_Algo(long Card_Num);
int main(void)
{
    long Card_Num;
    int start_Num;
    bool result;
    int Num_Digits;
    do {
        Card_Num = get_long("Number:");
        Num_Digits = Num_Length (Card_Num);
    }
    while ((Num_Digits != 13) && (Num_Digits != 15) && (Num_Digits != 16));
    
    start_Num = Card_Num / (pow(10, Num_Digits - 2));
    if ((start_Num == 34) || (start_Num == 37)){
        result = Peter_Luhn_Algo(Card_Num);
        if (result == true){
            printf("AMEX\n");
        }
        else
            printf("INVALID\n");
    }
    if ((start_Num > 50) && (start_Num < 56)){
        result = Peter_Luhn_Algo(Card_Num);
        if (result == true){
            printf("MASTERCARD\n");
        }
        else
            printf("INVALID\n");
    }
    if ((start_Num > 39) && (start_Num < 50)){
        result = Peter_Luhn_Algo(Card_Num);
        if (result == true){
            printf("VISA\n");
        }
        else
            printf("INVALID\n");
    }
}

//This function returns "true" if Luhn's Algorithms correct
//otherwise returns "false"
bool Peter_Luhn_Algo(long Card_Num){
    long Last_TwoNum; 
    long Remaining_Num; 
    int Sum1 = 0;
    int Sum2 = 0;
    int Total_sum = 0;
    int Num_Digits = Num_Length (Card_Num);
        for(int i = 0; i < Num_Digits; i+= 2){
            //100 is used to seperate last two didits ------xy
            Last_TwoNum = Card_Num % 100;
            int Left_Num = Last_TwoNum / 10;
            int Right_Num = Last_TwoNum % 10;
            //multiply left digits by 2 and add the products (digits only)
            Sum1 = Sum1 + ((2 * Left_Num))/10 + ((2 * Left_Num))%10;
            //add the remaining left digits 
            Sum2 = Sum2 + Right_Num;
            //100 is used to seperate rest of the digits 
            Remaining_Num = Card_Num / 100;
            Card_Num = Remaining_Num;
        }
    Total_sum = Sum1 + Sum2;
    //if the total's last digit is 0
    // the card is valid
    if ((Total_sum % 10 == 0))
    {
        return true;
    }
    else
       return false; 
}

// This function returns the length of the input numbers 
int Num_Length (long Card_Num){
    int len = 1;
    while (Card_Num > 10){
        Card_Num = Card_Num /10;
        ++len;
    }
    return len;
}
