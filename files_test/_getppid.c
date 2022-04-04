#include "main.h"

/**
 * main - program to print the PID of the parent process.
 * Return: 0 if success
 */

int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("PPID: %d\n", parent_pid);

	return (0);
}
