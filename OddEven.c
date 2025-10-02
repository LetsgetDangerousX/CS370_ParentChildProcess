
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[] )
{
    if(argc != 2) {
        printf("OddEven: Error - expected 1 argument\n");
        exit(1);
    }

    int number = atoi(argv[1]); // converts string to int
    printf("OddEven: %d is %s\n", number, (number % 2 == 0) ? "Even" : "Odd");
    exit(number);
}

