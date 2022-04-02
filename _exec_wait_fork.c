#include "main.h"

/**
 *
 *
 */

int main (void)
{
	pid_t child;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};
	int status, child_count = 0;

	while (child_count < 5)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error while creating a child process");
			exit(1);
		}
		if (child == 0)
		{
			printf("Child process ID: %d\n", getpid());
		
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Could not execute execve");
			}
		}
		else 
		{
			wait(&status);
			printf("This is the parent process ID: %d\n", getppid());
		}
	child_count++;
	}
	return (0);
}
