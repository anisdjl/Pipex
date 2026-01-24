/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths&args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:50:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/24 17:00:50 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path(t_data *data, t_paths *cmd)
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
		{
			free (path_v1);
			return (path_joined);
		}
		else
		{
			y++;
			free(path_joined);
		}
	}
	free (path_v1);
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
