#include "main.h"

/**
 * _getline - implementation for getting a string from the user
 * Return: string read
 **/

int main(int argc, char *argv[])
{
    char *line;
    char *returnVal = 0;

    returnVal = _getLine(&line);
    printf("%s", line);

    free(line);

    system("pause");
    return 0;
}

char *_getLine(char **line) {
    unsigned int lengthAdder = 1, counter = 0, size = 0;
    char *charRead = 0;
    char *buffer = NULL;
    size_t bufsize = 1024;

    buffer = malloc(bufsize * sizeof(char));

    *line = malloc(lengthAdder);
    charRead = gets(buffer);
    while(charRead != NULL) /*Seg Fault Here*/
    {
        *line[counter++] = charRead;
        *line = realloc(*line, counter);
    }

    *line[counter] = '\0';

    return charRead;
}
