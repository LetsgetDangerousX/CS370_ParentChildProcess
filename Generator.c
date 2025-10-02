#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// fork() to create child processes
// takes one mandatory arg, name of .txt file
// reads all lines in file and sends each line to first child process

/**
 * open file passed as argv[1]
 * read number
 * fork -> run OddEven
 * Wait -> get result
 * Fork -> Run Perfect Result
 * Wait -> get value
 * Fork -> Run Factorial with value
 * Wait -> get final result
 */

int main(int argc, char *argv[]) {
    if (argc != 2){
            printf("Usage: ./Generator <filename>\n");
            return 1;
        }
    

    FILE *file = fopen(argv[1], "r");
     if(!file){
        perror("Error opening file");
        return 1;
     }
     

     // set the buffert to hold eeach line from file
     char line[100];

     //read each line from the file:

     while(fgets(line, sizeof(line), file)) {    
      if(strlen(line) <= 1) continue;
      int status;                   // variable to hold child exit status
      int inputNum = atoi(line);       // number from input file
      int result;                   // result passed from child to child

      printf("===========================================\n");
      printf("Generator Process: Processing line \"%d\"\n", inputNum);
      printf("===========================================\n");


      // OddEven
      pid_t pidOdd = fork(); 

      if(pidOdd == 0){
         char numString[10];
         sprintf(numString, "%d", inputNum);

         execlp("./OddEven", "OddEven", numString, NULL);
         perror("exec failed for OddEven");
         exit(1);
      }else{
         printf("Waiting for the Child Process: (PID: %d)\n", pidOdd);
         waitpid(pidOdd, &status,0); // waiting for oddeven to finish
         result = WEXITSTATUS(status);
         printf("./OddEven Process finished (PID: %d). Returned: %d\n\n",pidOdd,result);
      }

      // run perfect square
      pid_t pidSQ = fork();

      if(pidSQ == 0){
         char numString[10];
         sprintf(numString, "%d", result);
         execlp("./PerfectSquare", "PerfectSquare", numString, NULL);
         perror("exec failed for PerfectSquare");
         exit(1);
      }else{
         printf("Waiting for the Child Process: (PID: %d)\n", pidSQ);
         waitpid(pidSQ, &status,0); // waiting for PerfectSquare to finish
         result = WEXITSTATUS(status);
         printf("./PerfectSquare Process finished (PID: %d). Returned: %d\n\n",pidSQ,result);
      }

      // run Factorial
      pid_t pidFac = fork();

      if(pidFac== 0){
         char numString[10];
         sprintf(numString, "%d", result);

         execlp("./Factorial", "Factorial", numString, NULL);
         perror("exec failed for Factorial");
         exit(1);

      }else{
         printf("Waiting for the Child Process: (PID: %d)\n", pidFac);
         waitpid(pidFac, &status,0); // waiting for Factorial to finish
         result = WEXITSTATUS(status);
         printf("./Factorial Process finished (PID: %d). Returned: %d\n\n",pidFac,result);
      }
     }
     fclose(file);
     return 0;
}
