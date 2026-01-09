/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths&args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:29:04 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/09 18:08:57 by adjelili         ###   ########.fr       */
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

char	**get_args(char *argv)
{
	char	**args;
	
	args = ft_split(argv, ' ');
	return (args);
}

char	*find_path(char **paths, char *args)
{
	int		y;
	char	*path_v1;
	char	*final_path;
	char	*path_joined;
	
	final_path = NULL;
	path_v1 = ft_strjoin("/", args);
	y = 0;
	while (paths[y])
	{
		path_joined = ft_strjoin(paths[y], path_v1);
		if (access(path_joined, F_OK | X_OK) == 0) // ici que je ne free pas ?
		{
			final_path = path_joined;
			free (path_v1);
			return (final_path);
		}
		else
		{
			y++;
			free(path_joined);
		}
	}
	free (path_v1);
	return (final_path);
}
