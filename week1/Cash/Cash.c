#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float change;
    int COUNT = 0;
    int cents;
    int quater = 25;
   int dime = 10;
    int nickel = 5;
    int penny = 1;

    do{
        change = get_float("Change owed: ");
    } while(change < 0);

    cents = (int) round(change * 100);

    while ((cents - quater) >= 0){
       cents = cents - quater;
       COUNT++; }

    while ((cents - dime) >= 0){
       cents = cents - dime;
       COUNT++; }

     while ((cents - nickel) >= 0){
       cents = cents - nickel;
       COUNT++; }

     while ((cents - penny) >= 0){
       cents = cents - penny;
       COUNT++; }

       printf("Coins used: %i \n", COUNT);
    }