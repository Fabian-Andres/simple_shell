#include "holberton.h"

/**
 * main - function main for shell.
 *
 * Return: options.
 */
int main(int arg_count, char *args[])
{
	while (1) /*true*/
	{
		char **options = NULL, *buffer;
		int characters;
		size_t bufsize = 1024;
		(void)arg_count;

		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			exit(1);
		}
		write(1, "#cisfun$ ", 9);

		characters = getline(&buffer, &bufsize, stdin);
		options = malloc(sizeof(char *));
		*options = malloc(sizeof(char) * characters);
		options = _get_command_and_options(buffer, characters);

		if (*options == NULL || options[0] == '\0')
		{
			free(*options);
			free(options);
			break;
		}
		_run_command(options, args[0]);
		

	}
	return (0);
}
