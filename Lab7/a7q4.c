#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	char *buffer[3];
	if(setuid(1000) == -1)
		printf("error");
	buffer[0] = "/bin/cat"; buffer[1] = argv[1]; buffer[2] = 0;
	if(execve(buffer[0], buffer, 0) < 0) {
		printf("exec error\n");
		return 0;
	}
	return 0;
}
