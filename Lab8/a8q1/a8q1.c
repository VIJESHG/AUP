#include<stdio.h>
#include<unistd.h>
#include <sys/acct.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define ACCFILE “/var/adm/pacct”

FILE *fp;
struct acct acdata;

unsigned long compt2ulong(comp_t comptime) {
	int val; int exp;
	val = comptime & 0x1fff; /* 13-bit fraction */
	exp = (comptime >> 13) & 7; /* 3-bit exponent (0-7) */
	while (exp-- > 0) val *= 8;
	return(val);
}
int wait2(long *rtime,long *wtime){
	int pid; 
	long temp;
	pid =  wait(NULL);
	fseek(fp, -sizeof(acdata), SEEK_END);
	fread(&acdata,  sizeof(acdata), 1, fp);
	//printf("%ld %ld\n", compt2ulong(acdata.ac_utime), compt2ulong(acdata.ac_stime));
	temp = compt2ulong(acdata.ac_utime) + compt2ulong(acdata.ac_stime);
	//printf("%ld\n", temp);	
	*rtime = temp;
	
	temp = compt2ulong(acdata.ac_etime - acdata.ac_utime - acdata.ac_stime);
	//temp = compt2ulong(acdata.ac_etime);
	//printf("%ld\n", temp);
	*wtime = temp;
	return pid;
}
int main(){
	long rtime, wtime, iotime, pid;
	fp = fopen("./a", "r");
	
	if((pid = fork()) > 0){
		printf("%ld ",pid);
		pid = wait2(&rtime, &wtime);
		
		printf("PID:%ld rtime: %ld wtime: %ld\n",pid, rtime, wtime);
	}else{
		int i;
		for(i = 0; i < 5;){
			i++;
		}
		exit(1);	
	}
}
