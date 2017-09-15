#include <stdlib.h> 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv) {
	char *str;
	str = (char*)malloc(128*sizeof(char));
 	int pid, status; 
 	int fd1,fd2;
 	if (argc != 3) {
 		 fprintf(stderr, "usage: %s output_file\n", argv[0]); exit(1); 
 	} 
 	if ((fd1 = open(argv[1],O_RDONLY)) < 0) { 
 		perror(argv[1]);  
 		exit(1); 
 	}
 	if ((fd2 = open(argv[2],O_WRONLY)) < 0) { 
 		perror(argv[2]);  
 		exit(1); 
 	} 
 	dup2(fd1,0);                    /* redirecting standard input to file1 */
 	dup2(fd2,1);			   	  /* redirecting standard output to file2 */
 	while(scanf("%s",str) != EOF)
 		printf("%s",str); 
 	exit(0);
 	
 	return 0; 
}
