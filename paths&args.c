/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths&args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:50:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 12:51:06 by adjelili         ###   ########.fr       */
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
