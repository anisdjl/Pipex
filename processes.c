/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:50 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 17:45:26 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	the_maestro(t_data *data)
{
	int	pipes[data->nb_pipes][2];
	int	pids[data->nb_cmd];

	initialize_pids(data->argc, pids);
	opening_pipes(data, pipes);
	the_loop(pids, data, pipes);
	close_pipes(data, pipes);
	ft_free_data(data);
	// wait here ?
	// return here ? ou bien un exit vu qu'on est pas dans le main avec le code d'erreur
	// ou bien si la valeur de l'exit du derier child est pas 0 j'exit ici sinon je reviens dans
	// main qui return 0
}

void	the_loop(int *pids, t_data *data, int pipes[data->nb_pipes][2])
{
	int	y;
	int	a;
	
	y = 2;
	while (y < data->argc - 1)
	{
		a = y - 2;
		pids[a] = fork();
		if (pids[a] == 0)
			childs(y, data, pipes);
		printf("%d\n", pids[a]);
		y++;
	}
}

void	first_cmd(t_data *data, int pipe_fd[data->nb_pipes][2])
{
	char	*args[2] = {"cat", NULL};
	int		fd;
	
	fd = open("test.txt", O_RDONLY);
	dup2(fd, 0);
	dup2(pipe_fd[0][1], 1);
	close(fd);
	close_pipes(data, pipe_fd);
	execve("/bin/cat", args, data->envp);
	exit(127);
}

void	last_cmd(t_data *data, int pipe_fd[data->nb_pipes][2])
{
	char	*args[3] = {"wc", "-l", NULL};
	int		fd;
	
	fd = open("result.txt", O_WRONLY);
	dup2(pipe_fd[0][0], 0);
	dup2(fd, 1);
	close_pipes(data, pipe_fd);
	close(fd);
	execve("/usr/bin/wc", args, data->envp);
	exit(127);
}

void	middle_cmd(t_data *data, int pipe_fd[data->nb_pipes][2])
{
	
}