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
        key = atoi(argv[1]);
        if(key < 0)
        printf("You must have entered a positive number");
    }

    plaintext = get_string("Plaintext: ");
    ciphertext = Encryption(key, plaintext);
    printf("Ciphertext: %s\n", ciphertext);
}

string Encryption(int Key, string Ptext){

    string Ctext = Ptext;
    char Alph_value;

    for (int i = 0; i < strlen(Ptext); i++){
		
		char current_letter = Ptext[i];

        if(isalpha(current_letter)){

            if(isupper(current_letter)){
				Alph_value = (current_letter + Key - 'A') % 26;
				Ctext[i] = Alph_value + 'A';
            }

            else {
				Alph_value = (current_letter + Key - 'a') % 26;
				Ctext[i] =  Alph_value + 'a';
            }
        }

        else
            Ctext[i] = current_letter;
       }
       return Ctext;
    }