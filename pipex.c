/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:13:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/04 15:19:10 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	int	id;
	int	n;
	int	i;
	
	id = fork();
	
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		();
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	return (0);
}