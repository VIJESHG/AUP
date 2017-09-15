#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
void list(char *path){
	struct stat fileStat;
	DIR *d;
	struct dirent *dir;
	printf("%s ",path);
	d = opendir(path);
	if(d){
		while((dir = readdir(d)) != NULL){
			if(strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") != 0){
				char new_path[128];
				strcpy(new_path,path);
				strcat(new_path,"/");
				strcat(new_path,dir->d_name);
				printf("%s ",dir->d_name);
				if(stat(new_path,&fileStat) >= 0){
					printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
					printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
					printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
					printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
					printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
					printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
					printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
					printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
					printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
					printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
					printf(" %lu",fileStat.st_nlink);
					printf(" %ld",fileStat.st_size);
					printf(" %s",ctime(&fileStat.st_atime));
				}
			}
		}
		closedir(d);
	}
}
void makedir(char *path){
	struct stat st = {0};
	DIR *d;
	struct dirent *dir;
	int i;
	if(stat(path,&st) == -1){
		mkdir(path,0700);
		printf("directory created..\n");
	}
	else
		printf("Directory already exists..\n");
	d = opendir(path);
	if(d){
		for(i = 0; i < 10; i++){
			char *he = "hello";
			char new_path[128];
			char str[3];
			sprintf(str,"%d",i);
			strcpy(new_path,path);
			strcat(new_path,"/");
			strcat(new_path,str);
			int fd1 = open(new_path, O_RDWR | O_CREAT, 0777);
			write(fd1,he,5);
			close(fd1);
		}
		closedir(d);
	}
}
int main(int argc, char *argv[]){
	struct stat st = {0};
	DIR *d;
	struct dirent *dir;
	int i;
	char path[128];
	strcpy(path,argv[1]);
	strcat(path,"/junk");
	makedir(path);
	list(path);
	chmod(path,333);
	list(argv[1]);
	chmod(path,777);
	list(path);
	chmod(path,666);
	chdir(path);
	chmod(path,777);
	chdir(path);
	return 0;
}					
