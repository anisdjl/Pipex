/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_and_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:50:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/27 10:37:24 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**get_paths(char **envp)
{
	int		y;
	char	**paths;
	char	*path;

	y = 0;
	while (envp[y])
	{
		if (ft_strncmp(envp[y], "PATH=", 5) == 0)
		{
			path = ft_strchr(envp[y], '/');
			paths = ft_split(path, ':');
			return (paths);
		}
		else
			y++;
	}
	return (NULL);
}

char	*find_path(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int		y;
	char	*path_v1;
	char	*path_joined;

	path_v1 = ft_strjoin("/", cmd->args[0]);
	y = 0;
	while (data->paths[y])
	{
		path_joined = ft_strjoin(data->paths[y], path_v1);
		if (access(path_joined, F_OK | X_OK) == 0)
			return (free (path_v1), path_joined);
		else
		{
			y++;
			free(path_joined);
		}
	}
	free (path_v1);
	ft_free_pipes(pipes, data);
	ft_free_data(data);
	ft_free_paths(cmd);
	ft_putstr_fd("pipex : command not found\n", 2);
	exit(127);
}

char	**get_args(t_data *data, t_paths *cmd, int y)
{	
	cmd->args = ft_split(data->argv[y], ' ');
	return (cmd->args);
}

void	ft_free_pipes(t_pipes *pipes, t_data *data)
{
	int	y;

	y = 0;
	if (pipes->pipes)
	{
		while (y < data->nb_pipes)
		{
			free(pipes->pipes[y]);
			y++;
		}
		free(pipes->pipes);
	}
	if (pipes->pids)
		free(pipes->pids);
	free(pipes);
}
