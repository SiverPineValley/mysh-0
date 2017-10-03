#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int temp = 0;
	char* stemp = strtok( (char*) command  , " " ); 
	
	*argv = (char**)calloc(5, sizeof(int));
	
	while (stemp != NULL) {
		if( temp >= 5 ) return;	
		argv[0][temp] = (char*)calloc(8096, sizeof(char));
		strcpy(argv[0][temp] ,stemp);
		stemp = strtok(NULL, " ");
		temp++;
	
}
	*argc = temp;

}
