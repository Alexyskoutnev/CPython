#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Python.h"


#define MAX_COMMAND 256

void init(){
	keyword();
}

void init_msg(){
	printf("Python 0.0.0 \n");
}

int main(int argc, char** argv){
	char command[MAX_COMMAND];
	char* args[MAX_COMMAND];
	int run = 1;
	init_msg();	
	while(run){
		printf(">>> ");
		fgets(command, MAX_COMMAND, stdin);
		if (command[strlen(command) - 1] == '\n'){
				command[strlen(command) - 1] = '\0';
		}
		
		char *tokens = strtok(command, " ");
		int i = 0;
		while(tokens != NULL){
			args[i++] = tokens;
			tokens = strtok(NULL, " ");
		}
		
		i = 0;	
		while (keywords[i]){
			if (strcmp(args[0], keywords[i]) && keywords[i] != NULL){
				printf("Found: %s", keywords[i]);
			}
			i++;
		} 

	}


	return 0;

}
