/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:50 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/24 17:22:28 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	the_loop(int *pids, t_data *data, t_paths *cmd, int pipes[data->nb_pipes][2])
{
	int	y;
	int	a;
	
	y = 2;
	while (y < data->argc - 1)
	{
		a = y - 2;
		pids[a] = fork();
		if (pids[a] == 0)
			childs(a, y, data, cmd, pipes);
		y++;
	}
}

void	first_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a)
{
	int		fd;
	
	fd = open(data->argv[1], O_RDONLY);
	dup2(fd, 0);
	dup2(pipe_fd[a][1], 1);
	close(fd);
	close_pipes(data, pipe_fd);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd(" pipex : command not found\n", 2);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}

void	last_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a)
{
	int		fd;
	
	fd = open(data->argv[data->argc - 1], O_WRONLY);
	dup2(pipe_fd[a - 1][0], 0);
	dup2(fd, 1);
	close_pipes(data, pipe_fd);
	close(fd);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd("pipex : command not found\n", 2);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}

void	middle_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a)
{
	dup2(pipe_fd[a - 1][0], 0);
	dup2(pipe_fd[a][1], 1);	
	close_pipes(data, pipe_fd);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd("pipex : command not found\n", 2);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}
