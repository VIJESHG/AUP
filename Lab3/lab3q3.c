#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main(){
	mode_t newMask,temp;	
    newMask = umask((mode_t) 0);               /* setting umask to zero  i.e it will not affect the current mask*/
    printf("Current mask = %o\n", (int) newMask); /* printing the current umask*/
    umask(newMask); /*again setting back the umask to its original value */                                
}

