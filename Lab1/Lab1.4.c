/*> ./a.out
  > ls -l file1.txt
  > ls -l file2.txt
  > od -c file1.txt
  > od -c file2.txt	
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
	int fd2;
	char buff3[2];
	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";
    int fd1 = open("file1.txt",O_RDWR);
    if ( fd1 < 0)
        printf("open failed..!!!");
    if (write(fd1, buf1, 10) != 10)
        printf("buf1 write error");

    if (lseek(fd1, 30, SEEK_SET) == -1)
        printf("lseek failed..!!");

    if (write(fd1, buf2, 10) != 10)
        printf("buf2 write failed..!!");
	
	fd2 = open("file2.txt", O_WRONLY);
	if(fd2 < 0)
		printf("open failed..!!");
	
	lseek(fd1,0,SEEK_SET);
	while(read(fd1,buff3,1) > 0){
			if(buff3[0] != 0)		
				write(fd2,buff3,1);
	}

	close(fd1);
	close(fd2);

}
