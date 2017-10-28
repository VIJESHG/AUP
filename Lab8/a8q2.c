#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
	int pid,childPid;
	if((pid = fork()) > 0){
		printf("Child pid: %d\n",pid);
		exit(1);
	}
	else if(pid == 0){
			int fd = open("/dev/tty", O_RDWR);
		if(fd == -1){
			perror("Error ");
			printf("The session doesn't have controlling terminal.\n");
		}
		else{
			printf("control terminal exists before setsid()\n");
		}	
		printf("old session id: %d\n",getsid(0));
		printf("new session id: %d\n",setsid());
		
		close(fd);
		
		fd = open("/dev/tty", O_RDWR);
		if(fd == -1){
			perror("Error ");
			printf("The session doesn't have controlling terminal after setsid()\n");
		}
	}
	return 0;
}
