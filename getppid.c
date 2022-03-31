#include <stdio.h>
#include <unistd.h>

/**
 * main - program to print the PID of the parent process.
 * Return: 0 if success
 */

int main(void)
{
	pid_t proc_id, parent_pid;

	proc_id = getpid();
	parent_pid = getppid();


	printf("Process ID: %d\n", proc_id);
	printf("Parent Process ID: %d\n", parent_pid);

	return (0);
}
