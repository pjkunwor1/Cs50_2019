#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    //prompt user to input correct height 
    do { 
       x = get_int("Height:");
    } while ( x < 1 || x > 8);
    int m = 1;
    
    //outer loop for each steps 
    for (int i = 0; i < x; i++) {
        //loops to print increasing steps 
        for (int j = 0; j < x - m; j++) {
            printf(" ");
            }
        for (int k = 0; k < m ; k++) {
            printf("#");   
            }
        printf("  ");
        //loops to print decreasing steps 
        for (int k = 0; k < m ; k++) {
            printf("#");   
            }
        for (int j = 0; j < x - m; j++) {
            printf(" ");
            }
        ++m; 
        printf("\n");
    }
}