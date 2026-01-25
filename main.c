/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:51:04 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 17:43:15 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	the_maestro(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int		i;
	int		status;

	status = 0;
	i = 0;
	initialize_pipes_pids(pipes, data, cmd);
	initialize_pids(data, cmd, pipes);
	opening_pipes(data, pipes, cmd);
	the_loop(data, cmd, pipes);
	close_pipes(data, pipes);
	ft_free_paths(cmd);
	while (i < data->nb_cmd - 1)
	{
		waitpid(pipes->pids[i], NULL, 0);
		i++;
	}
	waitpid(pipes->pids[i], &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	ft_free_pipes(pipes, data);
	ft_free_data(data);
	return (status);
}

int	creating(int argc, char **argv, char **envp)
{
	t_data	*data;
	t_paths	*cmd;
	t_pipes	*pipes;
	int		status;

	cmd = malloc(sizeof(t_paths));
	if (!cmd)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_free_paths(cmd);
		return (0);
	}
	pipes = malloc(sizeof(t_pipes));
	if (!pipes)
	{
		ft_free_data(data);
		ft_free_paths(cmd);
		return (0);
	}
	initialize_paths(cmd);
	initialize_data(data, argc, argv, envp);
	status = the_maestro(data, cmd, pipes);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	if (argc < 5)
	{
		write(2, "Pipex : not enough arguments\n",
			ft_strlen("Pipex : not enough arguments") + 1);
		return (0);
	}
	status = creating(argc, argv, envp);
	return (status);
}
