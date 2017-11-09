#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

static jmp_buf jb;

int sig_alrm(int signo){
	longjmp(jb, 1);
}

unsigned int sleep2(unsigned int secs){
	int time_left;
	time_left = alarm(0); 		/* unslept seconds left from previous alarm */
	printf("unslept seconds from previous alarm %d\n", time_left);
	if(setjmp(jb) == 0){
		alarm(secs - time_left); 	/* adding that time for user set value */
		pause();
	}
}

int main(){
	alarm(5);
	sleep2(7);
}

