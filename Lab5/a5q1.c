#include <stdio.h> 
#include <unistd.h> 
int main () {
 	pid_t pid; 
 	int status = 2; 
 	pid = fork(); 

 if (!pid) {
   puts("Child process\n"); 
   printf("CHILD PID  %d \n", getpid()); 
  	printf("     UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );
  puts("---------------------------------"); 
   return;
 } 

 wait(status); 

 printf("Father PID %d\n", getpid());
 printf("     UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );
 puts("--------------------------------"); 

 return 0; 
} 
