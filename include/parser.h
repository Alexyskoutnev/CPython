#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ARGS 32

void removeChar(char* str, char c);
void stripWhitespace(char* str);
void printOut(char** args, int cnt);
void callFunction(char* call);