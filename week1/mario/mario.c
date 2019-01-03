#include <stdio.h>
#include <cs50.h>

void CreatePyramid(numOfRows){

int i, j, k, l;

for (i = 0; i < numOfRows; i++){

    for(k = numOfRows; k > i; k--){
        printf(" ");
    }
    for(j = -1; j <= i; j++){
        printf("#");
    }
    printf("  ");

   for (l = -1; l <= i; l++){
        printf("#");
    }
    printf("\n");
}
 printf("\n");
}

int main (void){
    int n;
// promt the user for input
do{
    n = get_int("Enter a number: ");
    if (n > 20){
        printf("too high\n");
    }
    else if (n == 0) {
        printf("Cannot be equal to 0\n");
    }
    } while (n == 0 || n > 20);

    CreatePyramid(n);
}