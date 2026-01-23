/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:51:04 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 17:43:11 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	initialize_data(data, argc, argv, envp);
	the_maestro(data);
	return (0);
}
