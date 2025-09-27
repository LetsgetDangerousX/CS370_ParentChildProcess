#include <stdlib.h>
#include <stdio.h>

// fork() to create child processes
// takes one mandatory arg, name of .txt file
// reads all lines in file and sends each line to first child process

int main(int argc, char *argv[]) {

   
    int fd[2]; // file descriptor for the pipe
    pid_t pid;
    FILE *file_pointer;
    int number;
    char str_num[20];

    if (argc < 2){
            fprint(stderr, "Usage: %s <filename>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    

    file_pointer = fopen(argv[1], "r");

    
     if(file_pointer == NULL){
        perror("error opening file");
        exit(EXIT_FAILURE);
     }
    

     // fork 
     pid = fork();
     if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
     }

     // parenting

     if (pid > 0) {
        close(fd[READ_END]);
        
        // read in the numbers and write to pipe 

        // close the write end 
        // wait for child process to complete
        wait(NULL);

        

     }
}
