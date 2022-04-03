#include "main.h"

/**
 * _getline - implementation for getting a string from the user
 * Return: string read
 **/

char __getline(char **line);

int main(int argc, char *argv[])
{
    char *line;
    char returnVal = 0;

    returnVal = _getline(&line);
    printf("%s", line);

    free(line);

    system("pause");
    return 0;
}

char * _getline(char **line) {
    unsigned int lengthAdder = 1, counter = 0, size = 0;
    char *charRead = 0;

    *line = malloc(lengthAdder);
    while((charRead = gets(stdin)) != EOF && charRead != NULL) /*Seg Fault Here*/
    {
        *line[counter++] = charRead;
        *line = realloc(*line, counter);
    }

    *line[counter] = '\0';

    return charRead;
}
