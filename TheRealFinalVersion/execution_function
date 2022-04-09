#include "main.h"

void _execute_command(char **tokenized_input)
{
    pid_t child;
    struct stat st;
    int status, succes = 0;
    char *command = NULL;

    if (tokenized_input[0] != NULL)
    {
        if (_isletter(tokenized_input[0][0]) == 1)
        {
            command = tokenized_input[0];
            tokenized_input[0] = _realpath(tokenized_input, command);
            if (tokenized_input[0] == NULL)
            {
                free(tokenized_input[0]);
                return;
            }
            succes = 1;
        }
        if (stat(tokenized_input[0], &st) == 0)
        {
            child = fork();
            if (child == 0)
            {
                if (execve(tokenized_input[0], tokenized_input, environ) == -1)
                {
                    perror(tokenized_input[0]);
                    free(tokenized_input[0]);
                    free(tokenized_input);
                    exit(-1);
                }
            }
            else
                wait(&status);
                
            if (succes == 1)
                free(tokenized_input[0]);
        }
        else
        {
            write(STDOUT_FILENO, tokenized_input[0], _strlen(tokenized_input[0]));
            write(STDOUT_FILENO, ": not found\n", 12);
        }
    }
}

void _execute_command(char *realpath, char **tokenized_input)
{
    path = _getpath();
    command = _realpath(path, tokenized_input[0]);

    if (command == NULL)
    {
        _free(1, path), _free(1, command);
        return (-1);
    }

    child = fork();
    if (child == -1)
    {
        perror(NULL);
        return (-1);
    }
    if (child == 0) /*if it is 0 means that is the child process */
    {
        if (execve(command, tokenized_input, environ) == -1)
        {
            perror(NULL);
            _free(1, input), _free(1, path), _free(2, tokenized_input);
            return (0);
        }
    }
    else /* parent process - waits for the child process to finish */
        wait(&status);

    _free(1, input), _free(1, path), _free(2, tokenized_input);
}

void _execute_path(char *realpath, char **tokenized_input)
{
    child = fork();
    if (child == -1)
    {
        perror("Error while creating a child process");
        exit(4);
    }
    if (child == 0) /*if it is 0 means that is the child process */
    {
        if (execve(input, tokenized_input, environ) == -1)
        {
            perror(NULL); /*Con esto ya devuelve el mensaje por default*/
            _free(1, input), _free(1, path), _free(1, tokenized_input);
            return (0);
        }
    }
    else /* parent process - waits for the child process to finish */
        wait(&status);
}