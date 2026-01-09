/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:11:36 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/09 16:28:01 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void	ft_check_files(char *infile, char *outfile)
// {
// 	int	fd;

// 	if (access(infile, F_OK | R_OK) == -1)
// 	{
// 		perror(infile);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (access(outfile, F_OK) == -1)
// 	{
// 		fd = open(outfile, O_WRONLY | O_CREAT , 0644);
// 		if (fd == -1)
// 		{
// 			perror(outfile);
// 			close(fd);
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// 	else if (access(outfile, R_OK) == -1)
// 	{
// 		perror(outfile);
// 		exit(EXIT_FAILURE);
// 	}
// }
