#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
int main(){
	struct stat st;
	stat("file.txt",&st);
	int size =  st.st_size;
	int ret;
	char *buff;
	char *str = "hello";
	buff = (char*)malloc(sizeof(char)*128);
	int fd1 = open("file.txt",O_RDWR);
	if(fd1 == -1){
		printf("open failed..!!!");
	}
	int cnt = 0;
	while(cnt < size){	
		ret = read(fd1,buff,10);
		cnt += ret;
	}
    write(fd1,str,5);
	close(fd1);
	return 0;
}
