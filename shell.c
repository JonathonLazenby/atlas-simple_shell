#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* #define MAX_COMMAND_LENGTH 100 */

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

int main(void)
{
	char *command;
	size_t n = 0;
	pid_t pid;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		
		display_prompt();
		}

		if (getline(&command, &n, stdin) == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
	
		size_t len = strlen(command);
		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
        	{
            		execlp(command, command, NULL);
			fprintf(stderr, "Command '%s' not found\n", command);
			free(command);
			exit(EXIT_FAILURE);

		}
		else
		{
		int status;
		waitpid(pid, &status, 0);
		free(command);
		command = NULL;
		n = 0;
		}
	}
	return 0;
}
