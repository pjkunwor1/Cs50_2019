#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// the fuction takes two argument 
int main(int argc, string argv[])
{
    string text;
    if (argc != 2) {
        printf("Usage: %s keyword\n", argv[0]);
        return 1;
    }
    // receive the text input from user
    text = get_string("plaintext:");
    // the second argument of the main function is the key
    string key = argv[1];
    int key_len = strlen(key);
    int text_len = strlen(text);
    int k = 0; 
    int m = 0;
    // loop over the length of the user input text 
    for(int i = 0; i < text_len; i++){
        // This will ensure that the variable "k" will cyclically 
        // repeate after the key length 
        k = k % (key_len);
        // enter the condition if the letter of text is upper case 
        if(isupper(text[i])){
            // enter the loop if the letter of key is upper case 
            if(isupper(key[k])){
                // convert ASCII char value to shift key(m) in decimal 
                // ASCII value of 'A' is 65
                // 'A' is coverted to 0
                // 'B' is converted to 1 and so on 
                m = (int)((key[k])- 65);
                // ASCII value of upper case 'A' is 65
                // ASCII value of upper case 'Z' is 90
                // Because there are only 26 lettes from 'A' to 'Z'
                // Modulo with 90 insures that if current text + key > 90
                // it will loop back to first letter
                if ((int)((text[i] + m)) > 90){
                    // the modulo result is added with 64 to go back to ASCII
                text[i] = (((text[i] + m)) % 90) + 64;
                }
                else
                text[i] = text[i] + m;
                // move to the next key letter when condidtion is executed 
                ++k;
            }
            // enter the loop if the letter of key is lower case 
            if(islower(key[k])){
                // ASCII value of 'a' is 97
                // 'a' is coverted to 0
                // 'b' is converted to 1 and so on
                m = (int)((key[k])- 97);
                // modulo 90 because the letter of text is still upper case 
                if ((int)((text[i] + m)) > 90){
                text[i] = (((text[i] + m)) % 90) + 64;
                }
                else
                text[i] = text[i] + m;
                ++k;
            }
        }
        // enter the condition if the letter of text is lower case
        if(islower(text[i])){
            // enter the loop if the letter of key is upper case 
            if(isupper(key[k])){
                m = (int)((key[k])- 65);
                // modulo 122 because the letter is lower case
                // the ASCII value of lower case 'z' is 122
                if ((int)((text[i] + m)) > 122){
                text[i] = (((text[i] + m)) % 122) + 96;
                }
                else
                text[i] = text[i] + m;
                ++k;
            }
            // enter the loop if the letter of key is lower case 
            if(islower(key[k])){
                m = (int)((key[k])- 97);
                if ((int)((text[i] + m)) > 122){
                text[i] = (((text[i] + m)) % 122) + 96;
                }
                else
                text[i] = text[i] + m;
                ++k;
            }
        }
        else
            text[i] = text[i];
    }
    printf("ciphertext:%s\n", text);
}
