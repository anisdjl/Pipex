/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:50 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/31 12:40:51 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	the_loop(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int	y;
	int	a;

	y = 2;
	while (y < data->argc - 1)
	{
		a = y - 2;
		pipes->pids[a] = fork();
		if (pipes->pids[a] == 0)
			childs(y, data, cmd, pipes);
		y++;
	}
}

void	first_cmd(t_data *data, t_paths *cmd, t_pipes *pipes, int a)
{
	int		fd;

	fd = open(data->argv[1], O_RDONLY);
	dup2(fd, 0);
	dup2(pipes->pipes[a][1], 1);
	close(fd);
	close_pipes(data, pipes);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd("pipex : command not found\n", 2);
	close_pipes(data, pipes);
	ft_free_pipes(pipes, data);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}

void	last_cmd(t_data *data, t_paths *cmd, t_pipes *pipes, int a)
{
	int		fd;

	fd = open(data->argv[data->argc - 1], O_WRONLY);
	dup2(pipes->pipes[a - 1][0], 0);
	dup2(fd, 1);
	close_pipes(data, pipes);
	close(fd);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd("pipex : command not found\n", 2);
	close_pipes(data, pipes);
	ft_free_pipes(pipes, data);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}

void	middle_cmd(t_data *data, t_paths *cmd, t_pipes *pipes, int a)
{
	dup2(pipes->pipes[a - 1][0], 0);
	dup2(pipes->pipes[a][1], 1);
	close_pipes(data, pipes);
	execve(cmd->path, cmd->args, data->envp);
	ft_putstr_fd("pipex : command not found\n", 2);
	close_pipes(data, pipes);
	ft_free_pipes(pipes, data);
	ft_free_data(data);
	ft_free_paths(cmd);
	exit(127);
}
