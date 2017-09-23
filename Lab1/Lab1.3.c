#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
int main() {
	int fd;
	fd = open("f1",O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR);
	if(fd == -1){
		perror("error opening file.");
		return errno;
	}
	if(write(fd,"abcde",5) != 5){
		perror("error while writing..");
		return errno;
	}
	close(fd);
	fd = open("f1", O_WRONLY | O_APPEND);
	if(lseek(fd,0,SEEK_SET) != 0)
		printf("LSEEK failed...!!\n");
	if(write(fd,"12345",5) != 5){
		perror("error writing to file");
		return errno;
	}
	close(fd);
	return 0;
}
