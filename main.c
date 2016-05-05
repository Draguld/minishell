#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "libft.h"

#define		BUF_SIZE 1024

extern char		**environ;

int		ft_buildin(const char *userentry, char **envp)
{
	char			**argv = NULL;
	char			*buf = NULL;

	if (*userentry == '\0')
		return (-1);
	buf = ft_strtrim(userentry);
	if (ft_strcmp(buf, "") == 0 || buf == NULL)
		return (-1);
	argv = ft_strsplit(buf, ' ');
	free (buf);
	if (ft_strcmp(argv[0], "exit") == 0)
	{
		for (unsigned int i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free (argv);
		return (1);
	}
	else if (ft_strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
		{
			buf = ft_getstrenv(envp, "HOME=");
			chdir(buf);
			free (buf);
			buf = NULL;
		}
		else
		{
			chdir(argv[1]);
		}
		for (unsigned int i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free (argv);
		return (2);
	}
	for (unsigned int i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free (argv);
	return (0);
}

int		main()
{
	char	**path; //environement variable path in array.
	char	**argv; //cmd and all argument put by user.
	char	**envp; //copy of environ for write in.

	char	*buffer; //multiple use, user entry... ect.
	char	*find; //replacer of the char \n by \0.
	char	*file; //test access of file.
	char	*prompt; //the prompt (username and $>).

	int		paccess; //return the good path index.
	int		shellcmd; //use for build-in of minishell.

	pid_t	pid; //fork() indicator.

	buffer = getenv("PATH");
	envp = ft_arraydup(environ);
	path = ft_strsplit(buffer, ':');
	buffer = ft_getstrenv(environ, "USER=");
	prompt = ft_strconcat(buffer, "$> ");
	free (buffer);
	buffer = NULL;
	paccess = 0;
	shellcmd = 0;
	//Append the '/' char after all string to char **path.
	for (unsigned int i = 0; path[i] != NULL; i++)
	{
		buffer = ft_strapp(path[i], '/');
		free (path[i]);
		path[i] = buffer;
	//	free (buffer);
	}
	buffer = NULL;
	//Memory allocation for user command.
	buffer = (char*)malloc(sizeof(*buffer) * BUF_SIZE);
	while (42)
	{
		ft_putstr(prompt);
		fgets(buffer, BUF_SIZE, stdin);
		find = ft_strchr(buffer, '\n');
		if (find != NULL)
			*find = '\0';
		shellcmd = ft_buildin(buffer, envp);
		if (shellcmd == 0)
		{
			argv = ft_strsplit(buffer, ' ');
			paccess = ft_getaccess(path, argv[0]);
			if (paccess != -1)
			{
				file = ft_strconcat(path[paccess], argv[0]);
				pid = fork();
				if (pid == 0)
					execve(file, argv, envp);
				else
				{
					wait(NULL);
				}
				free(file);
				file = NULL;
			}
			else
			{
				ft_putstr(argv[0]);
				ft_putstr(": command doesn't exist!\n");
			}
			for (unsigned int i = 0; argv[i] != NULL; i++)
			{
				free (argv[i]);
				argv[i] = NULL;
			}
			free (argv);
			argv = NULL;
		}
		else if (shellcmd == 1)
			break;
	}
	for (unsigned int i = 0; path[i] != NULL; i++)
	{
		free (path[i]);
		path[i] = NULL;
	}
	for (unsigned int i = 0; envp[i] != NULL; i++)
	{
		free (envp[i]);
		envp[i] = NULL;
	}
	free (path);
	free (envp);
	free (prompt);
	free (buffer);
	path = NULL;
	prompt = NULL;
	buffer = NULL;
	return (0);
}
