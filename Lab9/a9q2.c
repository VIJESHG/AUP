#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void sig_usr(int signo){
	if(signo == SIGINT)
	printf("\nSignal caught!");
	return;
}
int main(void){
	pid_t pid, ppid;
	if((pid = fork()) == 0){
		ppid = getpid();
		printf("ppid = %d\n", ppid); 
		printf("Press ^c to kill parent..\n");
		kill(ppid, SIGINT);
		printf("After killing parent...\n");
	}
	else{
		printf("ppid-> %d pid-> %d ",ppid, pid);
		if(signal(SIGINT,sig_usr) == SIG_ERR)
			printf("Signal processed ");
		int time = sleep(5);
		printf("\nParent exiting with %d seconds left\n", time);
	}
	return 0;
}
