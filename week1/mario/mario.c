//  more comfortable

#include <stdio.h>
#include <cs50.h>

int main (void){
    int n;

    do{
    n = get_int("Enter a number: ");
    if (n > 20){
        printf("too high\n");
    }
    else if (n == 0) {
        printf("Cannot be equal to 0\n");
    }
    } while (n == 0 || n > 20);

int i, j, k, t;

for (i = 0; i < n; i++){

    for(k = n; k > i; k--){
        printf(" ");
    }
    for(j = 0; j <= i; j++){
        printf("#");
    }
    printf("  ");

   for (t = 0; t <= i; t++){
        printf("#");
    }
    printf("\n");
}
 printf("\n");
}
