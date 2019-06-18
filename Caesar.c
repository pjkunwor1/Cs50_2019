#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("Usage: %s key\n", argv[0]);
    }
    string s = get_string("Plaintext: ");
    //converts string to int 
    int key = atoi(argv[1]);
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (isupper(s[i])){
            if ((int)((s[i] + key)) > 90){
                s[i] = (((s[i] + key)) % 90) + 64;
            }
            else
            s[i] = ((s[i] + key));
        }
        else if (islower(s[i])){
            if ((int)((s[i] + key)) > 122){
                s[i] = (((s[i] + key)) % 122) + 96;
            }
            else
            s[i] = ((s[i] + key));
        }
        else
        s[i] = s[i];
    }
    printf("Ciphertext: %s\n", s);
}

