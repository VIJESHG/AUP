#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[]){
	struct stat fileStat;
	if(argc != 2){
		printf("Give file path as argument\n");
		return 0;
	}
	stat(argv[1],&fileStat);
	printf("Filename: %s\n",argv[1]);
	printf("File Type: ");
	switch (fileStat.st_mode & S_IFMT) {
		case S_IFBLK:  printf("Block Device\n");
			break;
		case S_IFCHR:  printf("Character Device\n");   
		    break;
		case S_IFDIR:  printf("Directory\n");
            break;
		case S_IFIFO:  printf("FIFO\n");               
			break;
		case S_IFLNK:  printf("Symlink\n");                 
			 break;
		case S_IFREG:  printf("Regular File\n");            
			 break;
		case S_IFSOCK: printf("Socket\n");                  
			 break;
		default:       printf("undefined file type:\n"); break;
	}
	printf("Device Number: %ld\n", (long) fileStat.st_dev);
	if(((fileStat.st_mode & S_IFMT) == S_IFBLK) || ((fileStat.st_mode & S_IFMT) == S_IFCHR)){
		printf("Major Number:  %ld\n", (long) major(fileStat.st_rdev));
		printf("Minor Number:  %ld\n", (long) minor(fileStat.st_rdev));
	}
	return 0;
}
