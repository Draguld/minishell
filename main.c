#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "libft.h"

#define		BUF_SIZE 1024

extern char		**environ;

int		main()
{
	char	**path = ft_strsplit(getenv("PATH"), ':');
	char	*buffer;

	for (unsigned int i = 0; path[i] != NULL; i++)
	{
		buffer = ft_strapp(path[i], '/');
		free (path[i]);
		path[i] = buffer;
	}
	buffer = NULL;

	buffer = (char*)malloc(sizeof(*buffer) * BUF_SIZE);

	while (42)
	{
		fgets(buffer, BUF_SIZE, stdin);
		
	}

	for (unsigned int i = 0; buffer[i] != '\0'; i++)
		printf("%d\n", (int)buffer[i]);

	ft_puttab_2s(path);
//	char *file = "/bin/ls";
//	char *arg[] = {"ls", NULL};
//	execve(file , arg, environ);
	return (0);
}
