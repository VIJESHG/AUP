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
		pid = fork();							//fork
		if (pid > 0) {
			printf("Parent started..\n"); 
			fd = open(argv[1],O_RDONLY);		//file opened in parent
			if(fd < 0)
				printf("open failed...!!!\n");
		}
		else{
			sleep(2);
			printf("Child started..\n");
			if(read(fd,str,128) < 0)			//reading from file opened by parent
				printf("Read from file opened by parent failed in child...\n");
			else
				printf("%s",str);
			printf("Child Exit..\n");
			return 0;			
		}
		wait(NULL);								//wait until child exits.						
		printf("Parent Exit..\n");
	return 0;
}
