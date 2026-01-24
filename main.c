/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:51:04 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/24 18:11:38 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	the_maestro(t_data *data, t_paths *cmd)
{
	int	pipes[data->nb_pipes][2];
	int	pids[data->nb_cmd];
	int	i;
	int	status;
//pipes = malloc(sizeof(int * 2) * data->nb_pipes);
	
	status = 0;
	i = 0;
	initialize_pids(data->argc, pids);
	opening_pipes(data, pipes);
	the_loop(pids, data, cmd, pipes);
	close_pipes(data, pipes);
	ft_free_data(data);
	ft_free_paths(cmd);
	while (i < data->nb_cmd - 1)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
	waitpid(pids[i], &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

int main(int argc, char **argv, char **envp)
{
	t_data	*data;
	t_paths	*cmd;
	int		status;

	cmd = malloc(sizeof(t_paths));
	data = malloc(sizeof(t_data));
	initialize_paths(cmd);
	initialize_data(data, argc, argv, envp);
	status = the_maestro(data, cmd);
	return (status);
}
