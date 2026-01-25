/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:57:02 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 17:41:04 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_data(t_data *data, int argc, char **argv, char **envp)
{
	data->paths = get_paths(envp);
	data->envp = envp;
	data->fd_infile = -1;
	data->fd_outfile = -1;
	data->argv = argv;
	data->argc = argc;
	data->nb_cmd = argc - 3;
	data->nb_pipes = argc - 4;
}

void	initialize_pids(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int	y;

	y = 0;
	pipes->pids = malloc(sizeof(int) * data->argc);
	if (!pipes->pipes)
	{
		ft_free_pipes(pipes, data);
		ft_free_paths(cmd);
		ft_free_data(data);
	}
	while (y < data->argc - 3)
	{
		pipes->pids[y] = 0;
		y++;
	}
}

void	initialize_paths(t_paths *cmd)
{
	cmd->args = NULL;
	cmd->path = NULL;
}

void	initialize_pipes_pids(t_pipes *pipes, t_data *data, t_paths *cmd)
{
	int	i;

	i = 0;
	pipes->pipes = malloc(sizeof(int *) * data->nb_pipes);
	if (!pipes->pipes)
	{
		ft_free_pipes(pipes, data);
		ft_free_paths(cmd);
		ft_free_data(data);
	}
	while (i < data->nb_pipes)
	{
		pipes->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes->pipes)
		{
			ft_free_pipes(pipes, data);
			ft_free_paths(cmd);
			ft_free_data(data);
			exit(0);
		}
		else
			i++;
	}
}
