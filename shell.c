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
	char *command = NULL, *token = NULL;
	size_t n = 0;
	pid_t pid;
	size_t len;
	int argc = 0, i = 0;
	char **argv = NULL;
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
		len = strlen(command);
		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}

		token = strtok(command, " ");
		while (token)
		{
			argc++;
			token = strtok(NULL, " ");
		}
		
		strtok(command, " ");
		
		argv = malloc(sizeof(char *) * (argc + 1));

		if (argv == NULL)
		{
			perror("Memory alloc failed\n");
			free(command);
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < argc; i++)
		{
			argv[i] = strtok(NULL, " ");
		}
		argv[argc] = NULL;

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			free(command);
			free(argv);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
        	{
            		execlp(command, command, NULL);
			fprintf(stderr, "Command '%s' not found\n", command);
			free(command);
			free(argv);
			exit(EXIT_FAILURE);

		}
		else
		{
		int status;
		waitpid(pid, &status, 0);
		free(command);
		free(argv);
		command = NULL;
		n = 0;
		}
		
	}
	return 0;
}
