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
	printf("Last access time: %s",ctime(&fileStat.st_atime));
	printf("Last status change time: %s",ctime(&fileStat.st_ctime));
	printf("Last modified time: %s",ctime(&fileStat.st_mtime));
	return 0;
}

/*A file's three timestamps are

    st_atime: Time of last file access
    st_mtime: Time of last file modification
    st_ctime: Time of last status change

Accessing a file's metadata via stat() seems unlikely to change any of these entries. stat() just access information in the inode, not in the file itself.
*/

/*This is confirmed by the results of this code by running it twice on the same file: */
