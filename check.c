/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:01:09 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 17:39:04 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_infile(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	if (access(data->argv[1], F_OK | R_OK) == -1)
	{
		ft_free_pipes(pipes, data);
		ft_free_paths(cmd);
		perror(data->argv[1]);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}

void	test_outfile(t_data *data, t_paths *cmd, t_pipes *pipes)
{
	int	fd;

	fd = open(data->argv[data->argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (fd == -1)
	{
		ft_error(data, cmd, pipes);
		close(fd);
		exit(1);
	}
	if (access(data->argv[data->argc - 1], W_OK) == -1)
	{
		ft_error(data, cmd, pipes);
		exit(1);
	}
	close(fd);
}

void	test_cmd(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
{
	if (data->argv[y][0] == '\0' || only_spaces(data->argv[y]))
	{
		ft_putstr_fd("pipex : command not found \n", 2);
		ft_free_pipes(pipes, data);
		ft_free_data(data);
		ft_free_paths(cmd);
		exit(127);
	}
	if (given_path(data, y))
	{
		cmd->path = data->argv[y];
		cmd->args = ft_split(data->argv[y], ' ');
	}
	else
	{
		cmd->args = get_args(data, cmd, y);
		cmd->path = find_path(data, cmd, pipes);
	}
}

int	given_path(t_data *data, int y)
{
	int	a;

	a = 0;
	while (data->argv[y][a])
	{
		if (data->argv[y][a] == '/')
			return (1);
		else
			a++;
	}
	return (0);
}

int	only_spaces(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}
