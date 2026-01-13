#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>

#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define INPUT_ERR 0

int main(int argv, char* argc[]) {
	
	if(argv < 2) { // taking the file name from the user
		printf("ERR! YOU HAVE TO ENTER THE FILE!!!\n");
		exit(INPUT_ERR);
	}

	exit(EXT_SUCCESS);
}
