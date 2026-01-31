/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:02:19 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/31 12:36:42 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

void	cmd_nfound(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	ft_putstr_fd("pipex : command not found \n", 2);
	close_pipes(data, pipes);
	ft_free_pipes(pipes, data);
	ft_free_paths(cmd);
	ft_free_data(data);
	exit(127);
}
