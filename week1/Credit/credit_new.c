#include <stdio.h>
#include <cs50.h>
long long ccNumberInput();

int main(void){
long long ccNumber = ccNumberInput();

}

long long ccNumberInput(){
	long long ccNum = 0, count = 0;
	do{
   count = 0;
   ccNum = get_long_long("Enter your credit card number: ");
   long long c = ccNum;
   while(c != 0){
       c = c / 10;
       ++count;
   }
} while(count < 13 || count > 16);
  return ccNum;
}

