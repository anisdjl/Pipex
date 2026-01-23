/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:26:11 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 17:58:17 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childs(int y, t_data *data, int pipes[data->nb_pipes])
{
	int	y;
	
	if (y == 2)
	{
		test_infile(data, y); // si problem exit avec le message
		test_cmd(data, y); // si probleme exit avec le message dans ce test pour le binary et le 'awk'
		first_cmd(data, pipes);
	}
	else if (y == data->argc - 2)
	{
		test_outfile(data, y); // si erreur exit avec le message
		test_cmd(data, y); // exit avec le message et c'est le code de celui la qu'on recupere
		last_cmd(data, pipes);
	}
	else
	{
		test_cmd(data, y); // si erreur affiche le code d'erreur + exit
		middle_cmd(data, pipes);
	}
}
