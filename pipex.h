/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:19:39 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/09 16:38:06 by adjelili         ###   ########.fr       */
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

// ============ args and paths ============ //

char	**get_args(char *argv);
char	**get_paths(char **envp);
char	*find_path(char **paths, char *args);
int		only_spaces(char *argv);
void	ft_check_commands(int argc, char **argv, char **paths);
void	ft_check_files(char *infile, char *outfile);
void	ft_check_args(int argc, char **argv);

// ============ libft ============ //

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_free_tab(char ***tab);


#endif