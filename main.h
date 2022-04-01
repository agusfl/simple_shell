#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Auxiliar functions */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);

/* Implementation functions */
char *_getline(void);
int _strtok(void);
int spaces(void);

#endif
