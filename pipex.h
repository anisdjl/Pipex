/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:48:12 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/23 17:46:19 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h> // a retirer absolument

#include <unistd.h> // write, read, close, pipe, fork, dup, dup2, execve, unlink
#include <fcntl.h> // open, unlink
#include <sys/types.h> // wait, waitpid
#include <errno.h>
#include <stdlib.h>

typedef struct paths
{
	char	**args;
	char	*path;
}	t_paths;

typedef struct data
{
	char	**paths;
	int		fd_infile;
	int		fd_outfile;
	char	**envp;
	char	**argv;
	int		argc;
	int		nb_cmd;
	int		nb_pipes;
}	t_data;

char	**get_paths(char **envp);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_free_tab(char ***tab);
void	initialize_data(t_data *data, int argc, char **argv, char **envp);
void	ft_free_data(t_data *data);
void	opening_pipes(t_data *data, int pipes[data->nb_pipes][2]);
void	first_cmd(t_data *data, int pipe_fd[data->nb_pipes][2]);
void	last_cmd(t_data *data, int pipe_fd[data->nb_pipes][2]);
void	close_pipes(t_data *data, int pipes[data->nb_pipes][2]);
void	initialize_pids(int argc, int pids[argc - 3]);
void	the_maestro(t_data *data);
void	childs(int y, t_data *data, int pipes[data->nb_pipes]);
void	middle_cmd(t_data *data, int pipe_fd[data->nb_pipes][2]);

#endif