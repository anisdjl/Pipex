/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:13:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/08 15:27:34 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		fd;
	int		pipe_fd[2];
	char	*args1[2] = {"cat", NULL};
	char	*args2[3] = {"wc", "-l", NULL};
	int		id1;
	int		id2;

	id2 = -1;
	if (pipe(pipe_fd) == -1)
	{
		printf("error while opening the pipe");
		return (0);
	}
	id1 = fork();
	if (id1 < 0)
		printf("error while forking ");
	if (id1 != 0)
		id2 = fork(); // on refait le fork que si on est dans le parent
	if (id1 == 0) // si on est dans le fils 1
	{
		close(pipe_fd[0]); // on ferme pcq on en a pas besoin
		fd = open("tests.txt", O_RDONLY);
		if (fd < 0)
			perror("cd"); // on ouvre le fichier qu'on veux lire
		dup2(fd, 0); // on redirige le fd 0 vers le fichiere
		dup2(pipe_fd[1], 1); // on redirige le fd 1 vers le pipe
		close(pipe_fd[1]); // on ferme le fd du pipe car on a deja le fd 1
		close(fd); // on ferme le fd
		execve("/bin/cat", args1, envp); // on execute la commande
	}
	if (id2 == 0) // si on est dans le fils 2
	{
		close(pipe_fd[1]); // on ferme le pipe d'ecriture
		fd = open("result.txt", O_WRONLY); // on ouvre le fichier en mode ecriture (je dois gerer la creation)
		dup2(fd, 1); // pareil que pour le fils 1
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		close(fd);
		execve("/usr/bin/wc", args2, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (0);
}
