/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:57:02 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 16:32:22 by adjelili         ###   ########.fr       */
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

void	initialize_pids(int argc, int pids[argc - 3])
{
	int	y;
	
	y = 0;
	while (y < argc - 3)
	{
		pids[y] = 0;
		y++;
	}
}
