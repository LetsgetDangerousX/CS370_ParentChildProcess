/**
 * PerfectSquare.c: Prints whether the number is a perfect square, 
 * then returns the number itself.
 * 
 * Tested with gcc -o PerfectSquare PerfectSquare.c -lm
 *  ./PerfectSquare 5
 * return not perfect for 5 and perfect for 16
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


// helper
int isPerfectSquare(int number) {
    int sqRoot = (int)sqrt(number);
    return sqRoot * sqRoot == number;
}
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("PerfectSquare: Error - Expected 1 argument\n");
        exit(1);
    }

    int number = atoi(argv[1]);


    if(isPerfectSquare(number)) {
        printf("PerfectSquare (PID: %d): %d is a PerfectSquare\n", getpid(), number);
    }else{
        printf("PerfectSquare (PID: %d): %d is not a PerfectSquare\n", getpid(), number);
    }

    exit(number);
}