/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:13:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/07 18:42:20 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include "ft_printf.h"
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	int		fd;
	int		pipe_fd[2];
	char	*args1[2] = {"cat", NULL};
	char	*args2[3] = {"wc", "-l", NULL};
	int		id1;
	int		id2;
	// if argc < 4 ne fais rien

	if (pipe(pipe_fd) == -1)
	{
		printf("error while opening the pipe");
		return (0);
	}
	id1 = fork();
	if (id1 != 0)
		id2 = fork(); // on refait le fork que si on est dans le parent
	if (id1 == 0) // si on est dans le fils 1
	{
		close(pipe_fd[0]); // on ferme pcq on en a pas besoin
		fd = open("test.txt", O_RDONLY); // on ouvre le fichier qu'on veux lire
		dup2(fd, 0); // on redirige le fd 0 vers le fichier
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
