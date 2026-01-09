/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:27:25 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/09 18:08:14 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_check_commands(int argc, char **argv, char **paths) 
{
	int		y;
	char	*path;
	char	**splitted_command;
	
	y = 2;
	while (y < argc - 1)
	{
		splitted_command = ft_split(argv[y], ' ');
		path = find_path(paths, splitted_command[0]);
		if (path == NULL)
		{
			printf("command not found\n");
			free(path);
			ft_free_tab(&splitted_command);
			exit(EXIT_FAILURE);
		}
		else
		{
			y++;
			free(path);
			ft_free_tab(&splitted_command);
		}
	}
	// ft_free_tab(&splitted_command);
	// free(path);
}

void	ft_check_files(char *infile, char *outfile)
{
	int	fd;

	if (access(outfile, F_OK) == -1)
	{
		fd = open(outfile, O_WRONLY | O_CREAT , 0644);
		if (fd == -1)
		{
			perror(outfile);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	if (access(infile, F_OK | R_OK) == -1)
	{
		perror(infile);
		exit(EXIT_FAILURE);
	}
	if (access(outfile, R_OK) == -1)
	{
		perror(outfile);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_args(int argc, char **argv)
{
	int	y;
	int	a;
	
	a = 0;
	y = 2;
	while (y < argc - 1)
	{
		a = 0;
		if (argv[y][0] == '\0' || only_spaces(argv[y]))
		{
			printf("command not found\n");
			exit(EXIT_FAILURE);
		}
		else
			y++;
	}
	return ;
}
