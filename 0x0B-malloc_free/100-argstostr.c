#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: pointer to an array of pointers of the arguments
 *
 * Return: pointer to new string containing all concatenated arguments
 */
char *argstostr(int ac, char **av)
{
	/**
	 * we need as many '\n' as there are strings
	 * so, we start our new memory length by
	 * reserving space for them 'len = ac'
	 */
	int i, j, len = ac, c = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++; /*get length of all characters */
	}

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL) /* handle malloc return */
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[c++] = av[i][j];
		str[c++] = '\n';
	}

	str[len] = '\0';

	return (str);
}
