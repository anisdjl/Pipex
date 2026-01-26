/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:26:11 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/26 10:08:36 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childs(int y, t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int	a;

	a = y - 2;
	if (y == 2)
	{
		test_infile(data, cmd, pipes);
		test_cmd(data, cmd, pipes, y);
		first_cmd(data, cmd, pipes, a);
	}
	else if (y == data->argc - 2)
	{
		test_outfile(data, cmd, pipes);
		test_cmd(data, cmd, pipes, y);
		last_cmd(data, cmd, pipes, a);
	}
	else
	{
		test_cmd(data, cmd, pipes, y);
		middle_cmd(data, cmd, pipes, a);
	}
}

void	ft_error(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	ft_free_pipes(pipes, data);
	ft_free_paths(cmd);
	perror(data->argv[data->argc - 1]);
	ft_free_data(data);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		a;

	a = 0;
	while (s[a])
		a++;
	new_str = malloc(sizeof(char) * a + 1);
	if (!new_str)
		return (0);
	a = 0;
	while (s[a])
	{
		new_str[a] = s[a];
		a++;
	}
	new_str[a] = '\0';
	return (new_str);
}

void	ft_extract_cmd(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
{
	char	**splitted_path;

	splitted_path = ft_split(data->argv[y], ' ');
	if (!splitted_path)
	{
		ft_free_pipes(pipes, data);
		ft_free_paths(cmd);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	cmd->path = ft_strdup(splitted_path[0]);
	ft_free_tab(&splitted_path);
}
