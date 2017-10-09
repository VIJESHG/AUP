#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_ARGS 64
int main(int argc, char **argv){
	int j;
	char buff[255];
	char *params[MAX_ARGS];
    char **next = params;	
	int fd = open(argv[1],O_RDONLY);
	if(fd <= 0){
		printf("Open failed..!!!\n");
		return 0;
	}
	read(fd,buff,255);
	close(fd);
	char *token = strtok(buff," \n");
	while(token != NULL){
		*next++ = token;
		printf("%s\n",token);
		token = strtok(NULL," \n");
	}
	*next = NULL;
	pid_t pid;
	if ((pid = fork()) == -1)
        perror("fork() error");
     else if (pid == 0) {
        execvp(params[0],params);
        printf("Return not expected. Must be an execvp() error.n");
     }
     wait(NULL);
	return 0;
}
