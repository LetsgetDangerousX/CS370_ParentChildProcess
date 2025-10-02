// OddEven.c: Prints whether the number is odd or even
// then returns the number itself.
/**
 * 
 * tested with : gcc -o OddEven OddEven.c
 * ./OddEven 5
 * returned 5 as odd
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[] )
{
    if(argc != 2) {
        printf("OddEven : Error - expected 1 argument]n");
        exit(1);
    }

    int number = atoi(argv[1]); // converts string to int
    printf("OddEven (PID: %d): %d is %s\n", getpid(), number, (number % 2 == 0) ? "Even" : "Odd");
    exit(number);
}

