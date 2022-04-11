#include "main.h"

/**
 * _execute_command - Function to execute commands
 * @path: Tokenized path
 * @tokenized_input: Tokenized Input
 * Return: Void
 **/

void _execute_command(char **path, char **tokenized_input)
{
	pid_t child;
	int status = 0;
	struct stat st;

	tokenized_input[0] = _realpath(path, tokenized_input[0]);
	if (stat(tokenized_input[0], &st) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror(NULL); /*Null return default message*/
		}
		if (child == 0) /*if it is 0 means that is the child process */
		{
			if (execve(tokenized_input[0], tokenized_input, environ) == -1)
			{
				perror(NULL); /*Null return default message*/

				return;
			}
		}
		else /* parent process - waits for the child process to finish */
		{
			wait(&status);
		}
	}
	else
		perror(NULL);
}

/**
 * _execute_path - Function to execute commands
 * @tokenized_input: Tokenized Input
 * Return: Void
 **/

void _execute_path(char **tokenized_input)
{
	pid_t child;
	int status = 0;
	struct stat st;

	if (stat(tokenized_input[0], &st) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror(NULL); /*Null return default message*/
			exit(-1);
		}
		if (child == 0) /*if it is 0 means that is the child process */
		{
			if (execve(tokenized_input[0], tokenized_input, environ) == -1)
			{
				perror(NULL); /*Null return default message*/
				return;
			}
		}
		else /* parent process - waits for the child process to finish */
		{
			wait(&status);
		}
	}
	else
		perror(NULL);
}
