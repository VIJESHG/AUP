#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_ARGS 64
int main(int argc, char *argv[]){
   execlp(argv[1],argv[2],argv[3],NULL);
   perror("execlp");   /* execve() returns only on error */
   exit(EXIT_FAILURE);
}

