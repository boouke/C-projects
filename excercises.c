#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function prototypes
int for_loop_excercise();
int num_c(int *max, char *err01, char *err02, char *buffer);
int even_or_odd_c(char *even_or_odd, char *buffer, char *err03);
int math(char *even_or_odd, int max, int sum, int i);

// Function initiating all other programs
int main(){
    printf("Starting program...\n");
    for_loop_excercise();
    return 0;
}

//The for loop excercise
int for_loop_excercise(){   
    int i = 1; //looping variable
    int sum = 0; //sum of integers in the math func
    char even_or_odd[4]; //type of result in math func
    int max; //max integer for math result
    char buffer[100]; //input buffer
    // error messages
    char err01[100] = "ERROR 01 - INPUT IS STRING. PLEASE INSERT A VALID NUMBER.\n";
    char err02[100] = "ERROR 02 - INVALID INTEGER. PLEASE INSERT A VALID NUMBER.\n";
    char err03[100] = "ERROR 03 - INVALID INPUT. PLEASE INSERT EITHER even OR odd.\n";
    //main part
    printf("Welcome to the program that gives you all of the integers below the one that you give, even or odd! Insert an integer.\n");
    num_c(&max, err01, err02, buffer);
    printf("You have selected %d!\nNow select if you want odd, or even numbers. Insert even or odd.\n", max);
    even_or_odd_c(even_or_odd, buffer, err03);
    math(even_or_odd, max, sum, i);
    return 0;
}

// Error handler for numbers
int num_c(int *max, char *err01, char *err02, char *buffer){
    while(scanf("%d", max) != 1 || max < 0){
        if(max < 0){
            printf("%s", err02);
            fgets(buffer, 100, stdin);
        }
        else{
            printf("%s", err01);
            fgets(buffer, 100, stdin);
        }
    }
    return 0;
}
// Error handler for type
int even_or_odd_c(char *even_or_odd, char *buffer, char *err03){
    while(scanf("%s", even_or_odd) != 1 || (strcmp(even_or_odd, "even") != 0 && strcmp(even_or_odd, "odd") != 0)){
        if((strcmp(even_or_odd, "even") != 0) && (strcmp(even_or_odd, "odd") != 0)){
            printf("%s", err03);
            fgets(buffer,100,stdin);
        }
    }
    return 0;
}
// Main calculation code
int math(char *even_or_odd, int max, int sum, int i){
    // for even
    if((strcmp(even_or_odd, "even") == 0)){
        for(i=1;i<=max;i++){
            if(i%2==0){
                sum += i;
                printf("Iteration : %d | Sum : %d | Memory Address : %p\n", i, sum, &i);
            }
        }
    }
    // for odd
    else{
        for(i=1;i<=max;i++){
            if(i%2!=0){
                sum += i;
                printf("Iteration : %d | Sum : %d | Memory Address : %p\n", i, sum, &i);
            }
        }
    }
    return 0;
}
// End of the for loop excercise