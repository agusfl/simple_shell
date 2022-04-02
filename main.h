#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/* Auxiliar functions */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void _free(int n, ...);

/* Implementation functions */
char *_getline(void);
char **_strtok(void);
int spaces(void);

#endif
