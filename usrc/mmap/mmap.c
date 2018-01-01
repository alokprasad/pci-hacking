#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv) {
	int fd = -1;
	int size = 4096;
	int status;
	char *area;
	pid_t pid;
	area = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANONYMOUS, fd, 0);
	pid = fork();
	if (0 == pid) {
		/* child */
		strcpy(area, "This is a message from the child");
		printf("Child has written: %s\n", area);
		exit(EXIT_SUCCESS);
	} else if (pid > 0){
		/* parent */
		wait(&status); /* wait until child terminates */
		printf("Parent has read: %s\n", area);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
