#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string Encryption();

int main (int argc, string argv[]){
    int key = 0;
    string plaintext = "";
    string ciphertext = "";

    // prompting the user for a valid input
    if (argc != 2){
        printf("You must have entered one number\n");
        exit(0);}
    else{
        key = atoi(argv[1]); // argv[1] - casting from string > integer
        if(key < 0)
        printf("You must have entered a positive number");
    }

    plaintext = get_string("Plaintext: ");
    ciphertext = Encryption(key, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
}

string Encryption(int Key, string Ptext){

    string Ctext = Ptext; // specifying the size (ciphertext should be equal o plaintext)
    char Alph_value_cipher;

    for (int i = 0; i < strlen(Ptext); i++) // iterating through the letters in plaintext
	{

		char current_letter = Ptext[i]; // taking a certain letter

        if(isalpha(current_letter)){ // checking is alphabetical

            if(isupper(current_letter)){
				Alph_value_cipher = (current_letter + Key - 'A') % 26; // formula to obtain the alphabetical value of the ciphertext
				Ctext[i] = Alph_value_cipher + 'A'; // back to ASCii value
            }

            else { // same for lowercase letters
				Alph_value_cipher = (current_letter + Key - 'a') % 26;
				Ctext[i] =  Alph_value_cipher + 'a';
            }
        }

        else
            Ctext[i] = current_letter; // for non-alphabetical values
       }
       return Ctext;
    }