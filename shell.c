#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 *
 *
 *
 *
 */

int  main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, i = 0, status, line;
	char **argv = NULL;
	pid_t child_pid;
	while (1)
	{
	printf("$ ");
	line = getline(&cmd, &n, stdin);
	if (line == -1)
	{
		exit(EXIT_SUCCESS);
	}
	 cmd_cpy = strdup(cmd);

	token = strtok(cmd, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}

	argv = malloc(sizeof(char *) * argc);

	token = strtok(cmd_cpy, delim);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	child_pid = fork();
	
	if (child_pid == -1)
	{
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error command not found.");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(&status);
	}
	i = 0;
	free(argv);
	free(cmd);
	free(cmd_cpy);
	}

return(0);

}
