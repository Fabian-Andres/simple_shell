#include "holberton.h"

/**
 * _result_fork - function to create fork.
 *
 * @options: options.
 * Return: void.
 */
void _run_command(char **options)
{
	int execve_status;
	pid_t id;

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
			}
			else
			{
				write(1, "./shell: No such file or directory\n", 36);
				exit(EXIT_FAILURE);
			}
		}
	}
}
