#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int status;
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1:
			perror("Fork Failed\n");
			exit(1);
		case 0:
			execl("../Q1/Q1", "../Q1/Q1", NULL);
			exit(1);
		default: 
			wait(&status);
			printf("Child Completed\n");
			break;
	}
}

