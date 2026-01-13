/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:19:16 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/13 16:44:57 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent(int argc, char **argv, char **paths, char **envp)
{
	int		pipe_fd[2];
	int		id1;
	int		id2;
	char	**args;
	char	*command_path;

	if (pipe(pipe_fd) == -1)
	{
		printf("error while opening the pipe\n");
		exit(EXIT_FAILURE);
	}
	id1 = fork();
	if (id1 != 0)
		id2 = fork();
	if (id1 == 0)
		ft_child1(argc, argc, paths, pipe_fd, envp);
	else if (id2 == 0)
		ft_child2(argc, argv, paths, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_free_tab(args);
	free (command_path);
}

void	ft_child1(char *path, char **args, char **paths, int *pipe_fd, char **envp)
{
	int	fd;

	close(pipe_fd[0]); // on ferme pcq on en a pas besoin
	fd = open("tests.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("cd"); // on ouvre le fichier qu'on veux lire
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0); // on redirige le fd 0 vers le fichiere
	dup2(pipe_fd[1], 1); // on redirige le fd 1 vers le pipe
	close(pipe_fd[1]); // on ferme le fd du pipe car on a deja le fd 1
	close(fd); // on ferme le fd
	execve("/bin/cat", args, envp); // on execute la commande et faut remplacer le /bin/cat par le path
}

void	ft_child2(char *path, char **args, char **paths, int *pipe_fd, char **envp)
{
	int	fd;
	
	close(pipe_fd[1]); // on ferme le pipe d'ecriture
	fd = open("result.txt", O_WRONLY); // on ouvre le fichier en mode ecriture (je dois gerer la creation)
	if (fd < 0)
	{
		perror("cd"); // on ouvre le fichier qu'on veux lire
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1); // pareil que pour le fils 1
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(fd);
	execve("/usr/bin/wc", args, envp);
}
