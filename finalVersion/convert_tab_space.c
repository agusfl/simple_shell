#include "main.h"

/**
 * convert_tab_space - function to convert tabs into spaces
 * @str: string to convert in case it has tabs ('\t')
 * Return: string converted or NULL.
 */

char *convert_tab_space(char *str)
{
        int i = 0;
        int x = 0;

        while (str[i] != '\0')
        {
                while (str[x] == '\t')
                {
                        str[x] = ' ';
                        x++;
                }
                i++;
                return (str);
        }
        return (NULL);
}
