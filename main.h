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

extern char **environ;

/* Auxiliar functions */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void _free(int n, ...);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
int ign_spaces_break_tab(char *str);
char *_strcat(char *dest, char *src);

/* Implementation functions */
char *_getline(void);
char **_strtok(char *str, int size);
int spaces(char *string);
void _ctrl_c(int sig);
char *_getpath();
int print_env(void);

#endif
