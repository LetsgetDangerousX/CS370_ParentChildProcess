/**
 * Factorial.c: Prints the factorial of the number, and returns the factorial value if it is ≤ 255; 
 * factorial 4 -> 4! = 4 x 3 x 2 x 1 = 24
 * otherwise returns n % 255.
 * 
 * Note: All Print statements must indicate the program that is responsible for generating them. To do this,
 * please prefix your print statements with the program name
 * tested with : gcc -o Factorial Factorial.c
 * ./Factorial 4
 * returned Factorial (PID 1514185): 4! = 24
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// helper
long long factorial(int i){
    if (i == 0 || i == 1) return 1; // 0! and !1 = 1
    return i * factorial(i - 1);
}

 int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Factorial: Error - expected 1 argument\n");
        exit(1);
    }

    int number = atoi(argv[1]);
    
   long long result = factorial(number);
    

    if(result <= 255){
        printf("Factorial: %d! = %lld\n", number, result);
        exit(result);
    }else{
        printf("Factorial: %d! = %lld\n",
          number, result); exit(number % 255);}

 }