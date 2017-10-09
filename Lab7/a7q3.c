#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc,char **argv){
	int fdr = open(argv[1],O_RDONLY);
	int fdw = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0777);
	pid_t pid = fork();
	if(pid == 0){
		dup2(fdr,0);
		dup2(fdw,1);
		execl("/bin/sh","sh","-c","cat",(char*)0);
		_exit(127);
	}
	if(waitpid(pid,NULL,0) != pid)
		return errno;
	return 0;
}
