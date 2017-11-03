#include<stdio.h>
#include<signal.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
static void sig_usr(int signo){
	if(signo == SIGTERM)
		printf("SIGTERM signal catched\n");
}
void quitproc(){
 		 printf("ctrl-\\ pressed to quit\n");
		 exit(0); /* normal exit status */
}

int main(){
	if(signal(SIGINT,SIG_IGN) == SIG_ERR)
		printf("can't Ignore SIGINT");
	if(signal(SIGTERM,sig_usr) == SIG_ERR)
		printf("can't catch SIGTERM");
	if(signal(SIGSEGV,SIG_DFL) == SIG_ERR)
		printf("can't catch SIGSEGV");
	if(signal(SIGQUIT,quitproc) == SIG_ERR)
		printf("can't catch SIGQUIT");
	for(; ;)
		pause();
}
