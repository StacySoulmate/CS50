/* uses cs50.h library, therefore works in their IDE: https://legacy.cs50.io/dashboard.html

This program encrypts the entered text using the key which is also entered
Read more about the task here: https://docs.cs50.net/2018/x/psets/2/vigenere/vigenere.html

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

string Encryption();


int main (int argc, string argv[])
{
    string plaintext = "";
    string ciphertext = "";
    string keyWord = "";


if(argc != 2){
    printf("Error\n");
    exit(0);
}
// iterating through each char in the argv[1] to make sure they are all letters
else{
    int lenOfarg1 = strlen(argv[1]);
    for (int i = 0; i < lenOfarg1; i++){
        if(isalpha(argv[1][i]))
            continue;

        else{
            printf("All the letters must be alhabetical\n");
            exit(0);
        }
    }
}

keyWord = argv[1];

plaintext = get_string("Plaintext: ");
ciphertext = Encryption(keyWord, plaintext);
printf("Ciphertext: %s\n", ciphertext);

}

string Encryption(string Key, string Ptext){

    int count_key = 0; // making sure the letters of the keyword are used only with letters of the plaintext
    string Ctext = Ptext;

    for (int i = 0; i < strlen(Ptext); i++){

        char Alph_value_cipher, Alpha_key; // vars of alphabetical values of the keyword and the ciphertext
		char current_letter = Ptext[i];

        if(isalpha(current_letter)){

          int j = count_key % strlen(Key); // wrapping aroung the keyword

            if(isupper(current_letter)){

                if(isupper(Key[j])) // also checking if the key letter is upper- or lowercase
                Alpha_key = Key[j] - 'A';

                else
                Alpha_key = Key[j] - 'a';

            	Alph_value_cipher = (current_letter + Alpha_key - 'A') % 26;
				Ctext[i] = Alph_value_cipher + 'A';

            }

            else {

                if(isupper(Key[j]))
                Alpha_key = Key[j] - 'A';

                else
                Alpha_key = Key[j] - 'a';

				Alph_value_cipher = (current_letter + Alpha_key - 'a') % 26;
				Ctext[i] =  Alph_value_cipher + 'a';
            }
            count_key++;
        }

        else
            Ctext[i] = current_letter;
    }
       return Ctext;
    }
