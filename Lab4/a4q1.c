#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void Print_env(char **envp){
	int i;
    for (i = 0; envp[i] != NULL; i++)
        printf("\n%s", envp[i]);
}
int main(int argc, char *argv[], char * envp[]){
    char * name = (char*)malloc(sizeof(char)*128);
    char * value = (char*)malloc(sizeof(char)*128);
    char *nameValue = (char*)malloc(sizeof(char)*256);
    printf("Env list before adding of new var:\n");
    Print_env(envp);
    printf("\n\nEnter the name and value of the environment var:\n");
    scanf("%s%s",name,value);
    strcpy(nameValue,name);
    strcat(nameValue,"=");
    strcat(nameValue,value);              
   	putenv(nameValue);
    printf("\n\nEnv list after adding of new var:\n");
    Print_env(envp);
    printf("\n%s=%s\n",name,getenv(name));
    return 0;
}
