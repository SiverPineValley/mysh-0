#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CL 16 //The max number of Argument lists

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int temp = 0;		// number of argument lists
	int utest = 0;		// variation for escape character Exception Handling
	int sptest = 0;		// variation for space character Exception Handling
	int countToken = 0;	// variation for counting the number of tokens
	char* sttemp;		// char pointer for replacement of command parameter
	char* tokentemp;	// char pointer for replacement of command parameter
	char* stemp;		// temporary storage variation for argument
	
	sttemp = (char*)calloc(strlen(command), sizeof(char*));
	strcpy(sttemp,command);
	//This code prevents the change of command parameter.
	
	while( utest <= strlen(sttemp) ) {
		if ( ( *( sttemp + utest  ) == '\n' ) || ( *( sttemp + utest ) == '\t' )  || ( *( sttemp + utest) == ' '   ) ) sptest++;
		if ( sptest == strlen(sttemp) ) {
			*argv = (char**)calloc( 1 , sizeof(char*));
			**argv = (char*)calloc(1, sizeof(char));
			strcpy( **argv, "" );
			*argc = 1;
			free(sttemp);
			return;
		}
		utest++;
	}	
	// Exception Handling for the line consisted only with escape character
	
	tokentemp = (char*)calloc(strlen(command), sizeof(char*));
	strcpy(tokentemp,command);
	stemp = strtok((char*) tokentemp, " \t\n");
	while (stemp != NULL  ) {
	countToken++;
	stemp = strtok(NULL, " \t\n");
	}
	free(tokentemp);

	// Count the total token number
	if ( countToken > MAX_CL  ) countToken = MAX_CL;
	
	stemp = strtok( (char*) sttemp  , " \t\n" ); 
	
	*argv = (char**)calloc( countToken, sizeof(char*));
	// Allocating the memory for argv.

	while (stemp != NULL) {
		
		*(*argv + temp) = (char*)calloc(strlen(stemp),sizeof(char));
		// Each parameter line length is equal to stemp.
		strcpy(*(*argv + temp) ,stemp);
		stemp = strtok(NULL, " \t\n");
		temp++;
		if ( temp ==  MAX_CL ) {
		*argc = temp;
		free(sttemp);
		return;
		}
		// Exception Handling for Command line overflow
}
	*argc = temp;
	free(sttemp);
	return;
}
