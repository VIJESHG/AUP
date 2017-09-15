#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv) {	
	int i= 0, pid,fd;
	char *str;
	str = (char*)malloc(sizeof(char)*128);
		pid = fork();
		if (pid > 0) {
			printf("Parent started..\n"); 
			fd = open(argv[1],O_RDONLY);
			if(fd < 0)
				printf("open failed...!!!\n");
		}
		else{
			sleep(2);
			printf("Child started..\n");
			if(read(fd,str,128) < 0)
				printf("Read from file opened by parent failed in child...\n");
			else
				printf("%s",str);
			printf("Child Exit..\n");
			return 0;			
		}
		wait(NULL);
		printf("Parent Exit..\n");
	return 0;
}
