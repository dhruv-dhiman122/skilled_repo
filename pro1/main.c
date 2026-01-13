#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>

//============================ Space for the macro ====================================//
#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define INPUT_ERR 0
//============================= Space for the global variable ==============================//

pthread_mutex_t mutex_lock;
pthread_t thread;

//================================ Space for user defined function ===============================//

void* dir_print(void* arg) { // function for printing the element of the dict
	pthread_mutex_lock(&mutex_lock);
	const char* FunctionName = (char*) arg;
	DIR* dir;
	struct dirent* entry;
	dir = opendir(FunctionName);
	while((entry = readdir(dir)) != NULL) {
		printf("%s\n",entry->d_name);
	}
	pthread_mutex_unlock(&mutex_lock);
	return NULL;
}

//==================================== Space for the main function ==============================//
int main(int argv, char* argc[]) {
	pthread_mutex_init(&mutex_lock, NULL);

	if(argv < 2) { // taking the file name from the user
		printf("ERR! YOU HAVE TO ENTER THE FILE!!!\n");
		exit(INPUT_ERR);
	}
	
	const char* user_name = argc[1];

	exit(EXT_SUCCESS);
}
