#include <cs50.h>
#include <stdio.h>
#include <math.h>
//Implement, in cash.c at right, a program that first asks the user how much change is owed
// and then prints the minimum number of coins with which that change can be made.

int main(void)
{
    float x = 0;
    do {
        x = get_float("Change owed:");
    }
    while(x < 0);
    // coverts user input from $ to cents 
    int cents = round(x* 100);
    int total_count = 0;
    int count = 0;
    int left = 0;
    //counts number of quaters
    if(cents/25 >= 1) {
        count = cents/25;
        left = cents%25;
        total_count = count;
    }
    //counts number of dimes
    if(left/10 >= 1) {
        count = left/10;
        left = left%10;
        total_count = total_count + count;
    }
    //counts number of nickels
    if(left/5 >= 1) {
        count = left/5;
        left = left%5;
        total_count = total_count + count;
    }
    //counts number of quaters cents
    if(left >= 1) {
        count = left/1;
        left = left%1;
        total_count = total_count + count;
    }
    printf("%d\n", total_count);
}
