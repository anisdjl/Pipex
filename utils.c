/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:02:19 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 16:36:09 by adjelili         ###   ########.fr       */
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

void	opening_pipes(t_data *data, int pipes[data->nb_pipes][2])
{
	int	i;
	
	i = 0;
	while (i < data->nb_pipes)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("problem while creating the pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes(t_data *data, int pipes[data->nb_pipes][2])
{
	int y;

	y = 0;
	while (y < data->nb_pipes)
	{
		close(pipes[y][0]);
		close(pipes[y][1]);
		y++;
	}
}