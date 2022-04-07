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

char *_getpath();
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
void _free(int n, ...);
char *_strcpy(char *dest, char *src);
char **_pathtok(char *str, int size);
int _colons(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strstr(char *haystack, char *needle);
