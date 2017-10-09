#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char store[8096];
	char *split;
	int index=0;
	char *del="\t\n ";

	*argv=(char**)malloc(9000*sizeof(char*));
	strcpy(store,command);			
	(*argv)[index]=(char*)malloc(9000*sizeof(char));
	split=strtok(store,del);

	if(split==NULL){
		index=1;
		strcpy((*argv)[0],"");
	}else{
		strcpy((*argv)[index],split);
	}

	while(split!=NULL){
		index+=1;

		(*argv)[index]=(char*)malloc(9000*sizeof(char));
		split=strtok(NULL,del);
		if(split==NULL) break;
		strcpy((*argv)[index],split);
	}
	*argc=index;
}
