/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_for_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:58:56 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/27 10:31:01 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	found_quote(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '\'')
			return (1);
		else
			a++;
	}
	return (0);
}

void	masquage(t_data *data, int y)
{
	int	a;
	int	btw_quote;

	btw_quote = 0;
	a = 0;
	while (data->argv[y][a])
	{
		if (!btw_quote && (data->argv[y][a] != '\''))
			a++;
		else if (data->argv[y][a] == '\'')
		{
			btw_quote = !btw_quote;
			a++;
		}
		else if (btw_quote)
		{
			if (data->argv[y][a] == ' ')
				data->argv[y][a] = 1;
			a++;
		}
	}
}

void	demasquage(t_paths *cmd, int y)
{
	int		a;
	char	*tmp;

	y = 0;
	while (cmd->args[y])
	{
		a = 0;
		if (found_quote(cmd->args[y]))
		{
			tmp = cmd->args[y];
			cmd->args[y] = ft_strtrim(cmd->args[y], "'");
			free(tmp);
			while (cmd->args[y][a])
			{
				if (cmd->args[y][a] == 1)
					cmd->args[y][a] = ' ';
				a++;
			}
		}
		y++;
	}
}

void	extract_args(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
{
	int	a;

	a = 0;
	masquage(data, y);
	cmd->args = ft_split(data->argv[y], ' ');
	if (!cmd->args)
	{
		ft_free_pipes(pipes, data);
		ft_free_paths(cmd);
		ft_free_data(data);
	}
	demasquage(cmd, y);
}
