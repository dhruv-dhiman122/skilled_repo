#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

//============================ Space for the macro ====================================//
#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define INPUT_ERR 0
#define BUFFER_SIZE 10
//============================= Space for the global variable ==============================//

pthread_mutex_t mutex_lock;
pthread_t thread1, thread2;
const char* fileName;
char buffer[BUFFER_SIZE];

//================================ Space for user defined function ===============================//

void* dir_print(void* arg) { // function for printing the element of the dict
	pthread_mutex_lock(&mutex_lock);
	const char* FunctionName = (char*) arg;
	DIR* dir;
	struct dirent* entry;
	dir = opendir(FunctionName);
	//printing the element of the dict
	while((entry = readdir(dir)) != NULL) {
		printf("%s\n",entry->d_name);
	}
	//asking the name of the file from the dict
	printf("Enter the file you want edit\n");
	char functionFileName[256];
	if(fgets(functionFileName,sizeof(functionFileName), stdin) == NULL) {
		printf("ERR!! FAILED TO TAKE INPUT FOR THE FILE");
		exit(INPUT_ERR);
	}
	fileName = (const char*) functionFileName;
	pthread_mutex_unlock(&mutex_lock);
	return NULL;
}

void* fileControl(void* arg) { // doing with the file work
	pthread_mutex_lock(&mutex_lock);
	int fd = open(fileName, O_RDWR | O_APPEND);
	ssize_t readByte;
	while((readByte = read(fd, buffer, BUFFER_SIZE)) != 0) {
		write(1, buffer,readByte);
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

	pthread_create(&thread1, NULL, dir_print, (void*)user_name);
	pthread_join(thread1, NULL);
	pthread_create(&thread2, NULL, fileControl, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex_lock);
	exit(EXT_SUCCESS);
}
