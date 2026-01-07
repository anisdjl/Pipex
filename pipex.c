/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:13:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/07 18:04:08 by anis             ###   ########.fr       */
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
		id2 = fork();
	if (id1 == 0)
	{
		close(pipe_fd[0]);
		fd = open("test.txt", O_RDONLY);
		dup2(fd, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		close(fd);
		execve("/bin/cat", args1, envp);
	}
	if (id2 == 0)
	{
		close(pipe_fd[1]);
		fd = open("result.txt", O_WRONLY);
		dup2(fd, 1);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		close(fd);
		execve("/usr/bin/wc", args2, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (0);
}
