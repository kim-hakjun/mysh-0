#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
	if(chdir(argv[1])!=0)
		printf("%s can't find.\n",argv[1]);
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  char buf[1000]; 
  getcwd(buf,1000);
  printf("%s\n",buf);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc!=2){	
	return 0;
  }else{
	if(strcmp(argv[0],"cd")!=0){
	return 0;
	}
	else return 1;
}
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc!=1){
	return 0;
  }else{ 
	  if(strcmp(argv[0],"pwd")!=0){
	return 0;
	}
	else return 1;
       }
}

