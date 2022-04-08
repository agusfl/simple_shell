/**
 * ign_spaces_break_tab - function to ignore spaces, break line and tab to use
 * in the main function.
 * @str: string to search for spaces and break line
 * Return: 1 if there is a space and a break line or 0 if there isnt
 */

int ign_spaces_break_tab(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
		/**
		 * 32 number representation of space character in ASCII
		 **/
		{
			return (1);
		}
		i++;
	}
	return (0);
}
