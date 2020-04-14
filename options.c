#include "holberton.h"

/**
 * _get_command_and_options - check the code for Holberton School students.
 *
 * @buffer: buffer.
 * @characters: characters.
 * Return: options.
 */
char **_get_command_and_options(char *buffer, ssize_t characters)
{
	char **options;
	char *token = strtok(buffer, " ");
	int i = 0;

	options = malloc(sizeof(char *));
	*options = malloc(sizeof(char) * characters);
	if (!options)
	{
		free(options);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		options[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	options[i] = NULL;
	options[i - 1] = strtok(options[i - 1], "\n");

	return (options);
}
