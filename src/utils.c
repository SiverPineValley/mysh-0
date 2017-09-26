#include "utils.h"
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int temp = 0;
	char* stemp = strtok( command  , " " ); 
	
	while (stemp != NULL) {	
		strcpy(**(argv + temp),stemp);
		stemp = strtok(NULL, " ");
		temp++;
	
}
	*argc = temp;


}
