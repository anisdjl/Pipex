/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:26:11 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 17:41:45 by adjelili         ###   ########.fr       */
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
