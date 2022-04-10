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
void *_calloc(unsigned int nmemb, unsigned int size);
void _free(int n, ...);
void _free_path(int n, ...);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _isletter(int c);
int _colons(char *str);
int spaces(char *str);
int ign_spaces_break_tab(char *str);
char *convert_tab_space(char *str);
char *_strdup(char *str);

/* Implementation functions */
char *_getline(void);
char **_getpath();
void _ctrl_c(int sig);
char **_strtok(char *str, int size);
char **_pathtok(char *str, int size);
int print_env(void);
char *_realpath(char **tokenized_input, char *command);

#endif
