/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:19:16 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/09 16:23:42 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// int main(int argc, char **argv, char **envp)
// {
// 	int 	y;
// 	int		pipe_fd[2];
// 	int 	id1;
// 	int 	id2;
// 	int 	fd;
// 	char	*final_path;
// 	char	**paths;
// 	char	**args;

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("pipe");
// 		return (0);
// 	}
// 	if (argc < 4)
// 		return (0);
	
// 	y = 2;
// 	id1 = fork();
// 	paths = get_paths(envp);
// 	if (id1 < 0)
// 	{
// 		perror("fork");
// 		return (0);
// 	}
	
// 	if (id1 != 0)
// 		id2 = fork();
	
// 	if (id1 == 0)
// 	{
// 		fd = open("test.txt", O_RDONLY);
// 		if (fd < 0)
// 		{
// 			printf("error");
// 			exit(EXIT_FAILURE);
// 		}
// 		dup2(fd, 0);
// 		dup2(pipe_fd[1], 1);
// 		close(pipe_fd[1]);
// 		close(pipe_fd[0]);
// 		close(fd);
// 		args = get_args(argv);
// 		final_path = find_path(paths, args[0]); // le final path sera recu dans la focntion pour pouvoir la free
// 		execve(final_path, args, envp);
// 	}
// }