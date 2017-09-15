#include <stdio.h>
#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h> // for truncate
#include <stdlib.h> // for system call
#include <sys/types.h>
#include <fcntl.h>
#include<sys/stat.h>

int truncat(char *path_name, int size) {
	int cnt;
	struct stat st;
	int file_size;
	char n = 0;
	char command[50];
	int fd;
	char *buffer;

	snprintf(command, sizeof(command) , "od -c %s" , path_name);
	
	if(access(path_name, W_OK) == 0) {
		stat(path_name, &st);
		file_size =  st.st_size;
		fd = open(path_name, O_RDWR);
		if(fd == 0) {
			printf("Error opening file\n");
			return -1;			
		}			
		if(file_size >= size){
			buffer = (char *)malloc(size+1);
			read(fd, buffer, size + 1);
			close(fd);
			fd = open(path_name, O_WRONLY | O_TRUNC);
			write(fd, buffer, size);
			printf("#File name :%s \n#File contents after truncate: \n ", path_name);
			system(command);
			printf("\n");
			close(fd);
		}
		else{
			cnt = 0;
			int temp = (size - file_size);
			fd = open(path_name, O_WRONLY);
			lseek(fd, 0, SEEK_END);
			//write(fd, buffer, file_size);
			while(cnt < temp) {
				write(fd,&n,1);
				cnt++;
			}			
			printf("#File name :%s \n#File contents after truncate: \n ", path_name);
			system(command);
			printf("\n");
			close(fd);			
		} 
	} else {
		printf("File dont have write permission");
		return -1;
	}
	return 0;
}

int main() {
	char path_name[50];
	char command[50];	
	int size;
	printf("#Please enter path :");
	scanf("%s", path_name);
	printf("#File name : %s \n#File contents before truncate: \n ", path_name);
	snprintf(command, sizeof(command) , "od -c %s" , path_name);
	system(command);
	struct stat st;
	stat(path_name, &st);
	printf("Original size = %zu\n", st.st_size);
	printf("#Please enter number to truncate file :");
	scanf("%d",&size);
	truncat(path_name, size);
	return 0;

}
