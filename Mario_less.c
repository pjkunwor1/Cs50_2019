#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height = 0;
    int k = 1;
    //prompt user to put correct height of Mario Stairs 
do {
    Height = get_int("Height:");
} while ( Height < 1 || Height > 8);

//outer loop for the height of stairs 
for (int m = Height ; m > 0; m--){
        //loop for the blanks 
       for(int i = Height ; i > 1; i--) {
        printf(" ");
        }
        //Actual loop for stairs 
        for(int j = 0; j < k; j++) {
        printf("#");
        }
    ++k;
    printf("\n");
  --Height;
    }
}