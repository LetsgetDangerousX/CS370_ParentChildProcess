
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
        printf("PerfectSquare: %d is a Perfect Square\n", number);
    }else{
        printf("PerfectSquare: %d is Not a Perfect Square\n", number);
    }

    exit(number);
}