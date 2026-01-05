/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:13:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/05 21:32:39 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include "ft_printf.h"
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	int	fd[2];
	int fd1[2];
	int	id;
	if (pipe(fd1) == -1)
		return (1);
	// fd[0] is for reading 
	// fd[1] is for writing
	if (pipe(fd) == -1)
	{
		printf("error while opening the pipe\n");
		return (1);
	}
	id = fork();

	if (id == 0)
	{
		close(fd[0]);
		int x;
		x = 42;
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		int y;
		close(fd[1]);
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("got from the child process %d\n", y);
	}

	if (id != 0)
	{
		close(fd1[0]);
		int anis = 12;
		write(fd1[1], &anis, sizeof(int));
		close(fd1[1]);
	}
	else
	{
		int anis2;
		close(fd1[1]);
		read(fd1[0], &anis2, sizeof(int));
		close(fd1[0]);
		printf("got from parent process %d\n", anis2);
	}
	
	return (0);
}