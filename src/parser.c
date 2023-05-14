#include "parser.h"

void removeChar(char* str, char c){
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++){
        if (str[i] != c){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void stripWhitespace(char* str){
    char *src = str;
    char *dst = str;
    while (*src){
        if (!isspace((char)*src)){
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

void printOut(char* args[], int cnt){
	for (int i = 0; i < cnt; i++){
		printf("%s", *args++);
	}
	printf("\n");	
}

void callFunction(char* call){
	char* token = strtok(call, "()");
	char* keyword_name = token;
	char* args_[MAX_ARGS];
    token = strtok(NULL, "()");
    char* args = strtok(token, ",");
    int i = 0;
	int cntArgs = 0;
    while (args != NULL){
        stripWhitespace(args);
        removeChar(args, '\"');
        args_[i++] = args;
        args = strtok(NULL, ",");
    }
	cntArgs = i;
	if (!strcmp(keyword_name, "print") && cntArgs != 0){
		printOut(args_, cntArgs);
	}
}
