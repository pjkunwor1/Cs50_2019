#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height = 0;
    int k = 1;
do {
    Height = get_int("Height:");
} while ( Height < 1 || Height > 8);
    
for (int m = Height ; m > 0; m--){
       for(int i = Height ; i > 1; i--) {
        printf(" ");
        }
        for(int j = 0; j < k; j++) {
        printf("#");
        }
    ++k;
    printf("\n");
  --Height;
    }
}