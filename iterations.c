#include <stdio.h>

int main() {
    int i = 1;
    int iterations = 0;
    int sum = 0;
    int prod = 1;
    int c = 0;
    char name[30];

    printf("Welcome to the program! Enter the amount of iterations. | ");
    scanf("%d", &iterations);
    while(iterations <= 0 ){
        printf("Invalid number. Please select a number above zero. | ");
        scanf("%d", &iterations);
    }
    printf("Type 1 to get a sum, 2 to get a product, or 0 if you want to get both. | ");
    scanf("%d", &c);
    while(c != 0 && c != 1 && c != 2){
        printf("Invalid number. Please select 0, 1 or 2. | ");
        scanf("%d", &c);
    }
    printf("What's your name mate? | ");
    scanf("%s", name);
    printf("Welcome %s!, here are your numbers.\n",name);
    for(i = 1; i<=iterations; i++){
        sum += i;
        prod *= i;
        if(c == 0){
            printf("ITERATION %d | SUM %d | PRODUCT %d\n",i,sum,prod);
        }
        else if(c == 1){
            printf("ITERATION %d | SUM %d\n",i,sum);
        }
        else if(c == 2){
            printf("ITERATION %d | PRODUCT %d\n",i,prod);
        }
    }
    return 0;
    }