//Credit Card Validator

#include <stdio.h>
#include <cs50.h>

int main(void){
long long cc_number;
long long c, count, numb;
int remainder;

// prompting a user for a valid input
do{
   count = 0;
   cc_number = get_long_long("Enter your credit card number: ");
   c = cc_number;
   while(c != 0){
       c = c / 10;
       ++count;
   }
} while(count < 13 || count > 16);

c, numb = cc_number;

// creating an array, filling the array with numbers
long long ArrayOfNumbers[count];

for (int i = 0; i < count; i++) {
  ArrayOfNumbers[i] = numb%10;
  numb = numb / 10;
}

// making the necessary calculations
int mutiply = 0, addition = 0;
    for (int i = 0; i < count; i++){
   
   if (i%2 != 0){
    c = ArrayOfNumbers[i] * 2;
    if (c > 9){
     while (c!=0){
     remainder = c%10;
     c  = c/10;
     mutiply += remainder;
     }
    }
    else{
     mutiply += ArrayOfNumbers[i] * 2;
    }
   }
    else{
     addition += ArrayOfNumbers[i];
    }
 }
     int final = addition + mutiply;
	 
	 // displaying if invalid number was entered
     if (final % 10 != 0){
      printf("INVALID");
      exit(0);
    }
	
	// displaying the cc company
     if (ArrayOfNumbers[count-1] == 3){
      printf("AMEX\n");
     }
     else if (ArrayOfNumbers[count-1] == 5){
      printf("MASTERCARD\n");
     }
     else if (ArrayOfNumbers[count-1] == 4){
      printf("VISA\n");
     }

     else {
      printf("INVALID\n");
     }

 }
