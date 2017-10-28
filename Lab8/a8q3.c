#define _POSIX_SOURCE
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
int main() {
  int option;
  pid_t pid;
  printf("Choose one of the options:\n => setpgid() after exec: 1\n => setpgid() before exec: 2\n");
  scanf("%d",&option);
  char *args[]={"./EXEC",NULL};
  switch(option){
  	case 1:
		if ((pid = vfork()) == 0) {
		  printf("Initially child's PGID is %d\n\n", (int) getpgrp());
		  execvp(args[0],args);
		}
		else {
		  sleep(2);
		  printf("Initially parent's PGID is %d\n\n", (int) getpgrp());
		  printf("parent is performing setpgid() on pid %d after exec.\n\n", (int) pid);
		  
		  if (setpgid(pid, 0) != 0)
		    perror("setpgid() error.");
		    
		  printf("PGIDS after performing setpgid() on child:\n");      
		  printf("parent's PGID is now %d\n", (int) getpgrp());
		  printf("child's PGID now %d\n", (int) getpgid(pid));
		}
		break;
	case 2:
		if ((pid = fork()) == 0) {
		  sleep(2);
		  execvp(args[0],args);
		}
		else {
		  printf("Initially child's PGID is %d\n\n", (int) getpgrp());
		   printf("Initially parent's PGID is %d\n\n", (int) getpgrp());
		  printf("parent is performing setpgid() on pid %d before exec.\n\n", (int) pid);
		  
		  if (setpgid(pid, 0) != 0)
		    perror("setpgid() error.");
		    
		  printf("PGIDS after performing setpgid() on child:\n");      
		  printf("parent's PGID is now %d\n", (int) getpgrp());
		  printf("child's PGID now %d\n", (int) getpgid(pid));
		  wait(NULL);  
		}
		break;
	}
  return 0;
}
