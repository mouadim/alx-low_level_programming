#include "main.h"
#include <stdlib.h>
/**
 * str_len - finds length of a given string
 * @str: the string to get its length
 *
 * Return: length of a string
 */
int str_len(char *str)
{
	int l = 0; /* hold string length */

	if (str != NULL)
	{
		while (str[l])
		l++;
	}
	return (l);
}
/**
 * no_of_words - count number of words in a given string
 * @str: the string to count its number of words
 *
 * Return: the number of words
 */
int no_of_words(char *str)
{
	int i = 0, w_count = 0;

	while (i <= str_len(str))
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			i++;
		}
		else if ((str[i] == ' ' || str[i] == '\0') && str[i - 1] != ' ')
		{
			w_count += 1;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (w_count);
}
/**
 * str_words - splits a stirng to words
 * @w_arr: the new array to store the words
 * @str: the string to split to words
 * @w_count: the number of words
 *
 * Return: a pointer to an array of words from the string
 */
char **str_words(char **w_arr, char *str, int w_count)
{
	int i, j = 0, w_size = 0, tmp = 0;

	if (w_arr != NULL)
	{
		for (i = 0; i <= str_len(str) && w_count; i++)
		{
			if (str[i] != ' ' && str[i] != '\0')
				w_size++;
			else if ((str[i] == ' ' || str[i] == '\0') && i && str[i - 1] != ' ')
			{
				w_arr[j] = (char *)malloc(sizeof(char) * w_size + 1);
				if (w_arr[j] != NULL)
				{
					while (tmp < w_size)
					{
						w_arr[j][tmp] = str[(i - w_size) + tmp];
						tmp++;
					}
					w_arr[j][tmp] = '\0';
					w_size = tmp = 0;
					j++;
				}
				else
				{
					while (j-- >= 0)
						free(w_arr[j]);
					free(w_arr);
					return (NULL);
				}
			}
		}
		w_arr[w_count] = NULL;
		return (w_arr);
	}
	else
		return (NULL);
}
/**
 * strtow - splits string into words
 * @str: the string to split to words
 *
 * Return: a pointer to an array of words
 */
char **strtow(char *str)
{
	char **w_arr;
	int w_count;

	if (*str == '\0' || str == NULL || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	w_count = no_of_words(str);

	if (w_count == 0)
		return (NULL);

	w_arr = (char **) malloc(sizeof(char *) * (w_count + 1));

	w_arr = str_words(w_arr, str, w_count);

	return (w_arr);
}
