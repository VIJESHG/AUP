#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include <sys/stat.h>
int main(){
	int fd = open("file",O_RDWR | O_APPEND);
	if(fd == -1){
		perror("open failed..!!");
		return errno;
	}
	char a[10];
	int r = read(fd,a,10);
	if(r <= 0){
		printf("read failed..");
	}
	int w = write(fd,"hello",5);
	if(w != 5){
		printf("write failed..");
	}
	return 0;
}
