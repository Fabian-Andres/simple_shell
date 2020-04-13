#include "holberton.h"


int main(void)
{
	while (1) /*true*/
	{
		char *buffer;

		size_t bufsize = 1024;
		int characters;
		char **options = NULL;


		pid_t id;
		int execve_status;

		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			exit(1);
		}
		printf("$ ");
		
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

		id = fork();
		if (id == 0)
		{
			char *env_args[] = { (char *)0 };

			execve(options[0], options, env_args); 
			exit(0);
		}
		else
		{
			if (waitpid(id, &execve_status, 0) > 0) 
			{
				if (WIFEXITED(execve_status) && !WEXITSTATUS(execve_status))
				{
					/*Execve is successful*/
					/* for(i = 0; options[i]; i++) */
					/* { */
					/* 	free(options[0]); */
					/* } */
					/* free(options);	 */
				}
				else
				{
					printf("execv failed\n");
					exit(EXIT_FAILURE);
				}
			}
		}
		free(buffer);  	
	}
	return (0);
}