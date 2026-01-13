#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>

//============================ Space for the macro ====================================//
#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define INPUT_ERR 0
//============================= Space for the global variable ==============================//

pthread_mutex_t mutex_lock;
pthread_t thread;

//================================ Space for user defined function ===============================//


//==================================== Space for the main function ==============================//
int main(int argv, char* argc[]) {
	
	if(argv < 2) { // taking the file name from the user
		printf("ERR! YOU HAVE TO ENTER THE FILE!!!\n");
		exit(INPUT_ERR);
	}

	exit(EXT_SUCCESS);
}
