#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int temp = 0;
	char* sttemp = (char*) command;
	*(sttemp + strlen(sttemp) - 1 ) = '\0';
	// change the line feed character from '\n' to '\0'
	
	char* stemp = strtok( (char*) sttemp  , " " ); 
	
	*argv = (char**)calloc(5, sizeof(char*));
	// I select the maximum parameter number to 5

	while (stemp != NULL) {
		
		*(*argv + temp) = (char*)calloc(50, sizeof(char));
		// Each parameter line length is at most 50.
		strcpy(*(*argv + temp) ,stemp);
		stemp = strtok(NULL, " ");
		temp++;
	
}
	*argc = temp;

}
