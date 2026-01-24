/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:26:11 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/24 18:05:59 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childs(int a, int y, t_data *data, t_paths *cmd, int pipes[data->nb_pipes][2])
{
	if (y == 2)
	{
		test_infile(data);
		test_cmd(data, cmd, y); // si probleme exit avec le message dans ce test pour le binary et le 'awk'
		first_cmd(data, cmd, pipes, a);
	}
	else if (y == data->argc - 2)
	{
		test_outfile(data);
		test_cmd(data, cmd, y);
		last_cmd(data, cmd, pipes, a);
	}
	else
	{
		test_cmd(data, cmd, y);
		middle_cmd(data, cmd, pipes, a);
	}
}
