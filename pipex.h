/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:48:12 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/24 18:04:24 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <wait.h>

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
void	first_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a);
void	last_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a);
void	close_pipes(t_data *data, int pipes[data->nb_pipes][2]);
void	initialize_pids(int argc, int pids[argc - 3]);
int		the_maestro(t_data *data, t_paths *cmd);
void	childs(int a, int y, t_data *data, t_paths *cmd, int pipes[data->nb_pipes][2]);
void	middle_cmd(t_data *data, t_paths *cmd, int pipe_fd[data->nb_pipes][2], int a);
void	test_infile(t_data *data);
void	test_outfile(t_data *data);
int		only_spaces(char *argv);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	the_loop(int *pids, t_data *data, t_paths *cmd, int pipes[data->nb_pipes][2]);
void	initialize_paths(t_paths *cmd);
char	*find_path(t_data *data, t_paths *cmd);
char	**get_paths(char **envp);
char	**get_args(t_data *data, t_paths *cmd, int y);
int		given_path(t_data *data, int y);
void	test_cmd(t_data *data, t_paths *cmd, int y);
void	ft_free_paths(t_paths *cmd);

#endif