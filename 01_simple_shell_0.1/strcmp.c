#include "holberton.h"

/**
 * _strcmp - function that compare two strings.
 * @s1: string1 for compare.
 * @s2: string1 for compare.
 * Return: 0 if success
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != 0; a++)
	{
	}
	for (a = 0; s2[a] != 0; a++)
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	}
	return (0);
}
