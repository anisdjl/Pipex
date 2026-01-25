/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:02:19 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 17:45:07 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char ***tab)
{
	int	y;

	y = 0;
	while ((*tab)[y])
	{
		free ((*tab)[y]);
		y++;
	}
	free (*tab);
	tab = NULL;
}

void	ft_free_data(t_data *data)
{
	if (data->paths)
		ft_free_tab(&data->paths);
	free(data);
}

void	opening_pipes(t_data *data, t_pipes *pipes, t_paths *cmd)
{
	int	i;

	i = 0;
	while (i < data->nb_pipes)
	{
		if (pipe(pipes->pipes[i]) == -1)
		{
			ft_free_pipes(pipes, data);
			ft_free_paths(cmd);
			ft_free_data(data);
			perror("problem while creating the pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes(t_data *data, t_pipes *pipes)
{
	int	y;

	y = 0;
	while (y < data->nb_pipes)
	{
		close(pipes->pipes[y][0]);
		close(pipes->pipes[y][1]);
		y++;
	}
}

void	ft_free_paths(t_paths *cmd)
{
	if (cmd->args)
		ft_free_tab(&cmd->args);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}
