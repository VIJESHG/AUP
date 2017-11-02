#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv){ 
	int fd, pid; 
	char buf[10];
	fd = open("xyz", O_RDWR);
	sprintf(buf, "%d", fd);
	char *const parmList[] = {"./child",buf, NULL};
	fcntl(fd, F_SETFD, argv[2]);
	pid = fork();
	if(pid == 0) {
		execvp("./child",parmList);
	}
	wait(NULL);
	return 0;
}
