#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc, char **argv) {	
	int i= 0, pid;
	int n = atoi(argv[1]);				//no. of processes
	for(i = 0; i < n; i++) {
		if (pid = fork() == 0) { 			//child
			printf("Child %d\n",i);	
			sleep(atoi(argv[2]));			//sleeping
			printf("exit child %d\n",i);
			return 0;
			
		}
	}
	while(wait(NULL) > 0);					//wait until all child exits.
	printf("All the children have completed the execution..\n");
	return 0;
}
