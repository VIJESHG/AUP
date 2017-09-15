#include <stdio.h>
#include <setjmp.h>
#include<stdlib.h>
static jmp_buf env;		/* Declare a global jmp_buf variable that is available to both func and main */	
static int e;   /*global value*/

void function2(void){
    printf("Starting function2\n");
    
    /* Return to main with a return code of 1 (can be anything except 0) */
    longjmp(env, 1);
    /* In case of longjmp call, the variables that are stored in memory will have values as of the time of longjmp, while variables 	       stored in registers are restored to their values when setjmp was called.
	   
	   Therefore values of automatic and regiter get changed to their original value */ 
    printf("Finishing function2\n"); /* This will never be executed! */
}
                  
void function1(int a,int b, int c,int d){
    printf("Starting function1\n");
	printf("auto a = %d static b = %d register c = %d volatile d = %d global e = %d\n",a,b,c,d,e);
	
	    
    /* Return to main with a return code of 1 (can be anything except 0) */
    function2();

    /* Display a message indicating we are leaving func */
    printf("Finishing function1\n"); /* This will never be executed! */
}

int main(int argc, const char * argv[]){
    /* Define temporary variables */
    auto int a;						/*local auto var declaration */
    static int b;				/*static var declaration*/
    register int c;				/*register var declaration*/
    volatile int d;				/*volatile var declaration*/
    int result;			

	/*setting values of variables before setjump */
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 5;
	
    printf("Starting main\n");
	printf("auto a = %d static b = %d register c = %d volatile d = %d global e = %d\n",a,b,c,d,e);
    
    
    /* If the result of setjump is not 0 then we have returned from a call to longjmp */
    if(setjmp(env) != 0){
    	 printf("\nValues of the variables after longjump:\n");
		 printf("auto a = %d static b = %d register c = %d volatile d = %d global e = %d\n",a,b,c,d,e);
		 exit(0);
	}
	a = 51;
	b = 52;
	c = 53;
	d = 54;
	e = 55;
	
    /* Call func */
    function1(a,b,c,d);
    printf("Finished main\n");
	exit(0);
}
