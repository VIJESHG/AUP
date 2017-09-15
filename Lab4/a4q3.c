#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
double getEffectiveTime(struct timeval startTime, struct timeval endTime){
	return (endTime.tv_usec - startTime.tv_usec) + (endTime.tv_usec - startTime.tv_usec);
}	
int main(){
	struct timeval startTime, endTime;
	double totalTime;
	pid_t pid;
	int i;
	printf("Time analysis of getpid():\n");
	totalTime = 0.0;
	for(i = 0; i < 10; i++){
		gettimeofday(&startTime, NULL);
		pid = getpid();
		gettimeofday(&endTime, NULL);
		totalTime += getEffectiveTime(startTime, endTime);
	}
	printf("Average time of getpid() - %lf microsec\n", totalTime/10);
	printf("\n\n");
	printf("Time analysis of fork():\n");
	totalTime = 0.0;
	for(i = 0;i < 10; i++){
		gettimeofday(&startTime, NULL);
		int PID = fork();
		gettimeofday(&endTime, NULL);		
		if(PID)
			totalTime += getEffectiveTime(startTime, endTime);
		
		else 
			exit(0);
	}
	printf("Average time of fork() - %lf microsec\n", totalTime/10);
	return 0;
}


