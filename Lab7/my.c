#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int j,n,fd1,fd2;
    char buff[80];
			f = open(argv[0],O_RDONLY);
       		while((n = read(f,buff,80)) > 0)
              printf("%s",buff);
             
             exit(EXIT_SUCCESS);
}
