#include <dirent.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
int file_index = 0;        
struct params {									/*Parameters struct*/
    char file_names [255];
    char word[255];           
};
void *search(void *args){						/*thread function*/						
    struct params *temp = args;

    FILE *fp; 
    char line[255]="";      
    fp = fopen(temp->file_names, "r");

    if(fp == NULL){
        perror("Error: File open failure.");
    }
    else{
        while(fgets(line,255, fp)){				/*read and tokenize each line and search using strstr() */
		    char *token = strtok(line, " \t");
			while (token != NULL){
				if (strstr(token,temp->word) != NULL){
		    		printf("Pattern found:[ %s ] in file %s \n", strstr(token,temp->word), temp->file_names);
		    		fclose(fp);
		    		return (void*) 1;	
		    	}        	
		    	token = strtok(NULL, " \t");
			}
		}
    }
    fclose(fp);
    return (void*) 0;
}

int main(int argc, char const* argv[]) {
	void *result;
	char dir_path[255];
	char word[255];
    DIR * dir_pointer;          
    struct dirent * entry;      
    int count;
	printf("Enter the path of dir containing all files:");
	scanf("%s",dir_path);
	printf("Enter number of files to be scanned:");
	scanf("%d",&count);
	printf("Enter word to be searched:");
	scanf("%s",word); 
    struct params pars[count];
    pthread_t threads[count];
	
    if ((dir_pointer = opendir(dir_path)) == NULL) {
    	printf("can't open directory\n");
    	return 0;
  	}
    while( (entry = readdir(dir_pointer)) != NULL){
        if(entry->d_type == DT_REG){ 						/*access only regular files i.e avoid the . and .. dir */
            char full_path[255];     
            full_path[0] = '\0';   
            strcat(full_path, dir_path);  					// concatenate file directory;
            strcat(full_path, entry->d_name);    			// concatenate filename;
            strcpy(pars[file_index].file_names, full_path); // store file name into file_names array;
            strcpy(pars[file_index].word,word);
            pthread_create(&threads[file_index], NULL, search, &pars[file_index]);  //create thread for each file
            file_index++;   					
        }
    }
    for(int i = 0; i < count; i++){
        pthread_join(threads[i],&result);
        if((int*)result)
 			return 0;
    }
    printf("Word not found..!!!\n");
    return 0;
}
