// #include<stdlib.h>
// #include <stdio.h>
#include "pipex.h"

// int	is_charset(char c, char *charset)
// {
// 	int	i;

// 	i = 0;
// 	while (charset[i])
// 	{
// 		if (charset[i] == c)
// 		{
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_countwords(char *str, char *charset)
// {
// 	int	cwords;
// 	int	i;

// 	cwords = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((is_charset(str[i], charset) != 1)
// 			&& (is_charset(str[i + 1], charset) == 1 || str[i + 1] == '\0'))
// 		{
// 			cwords++;
// 		}
// 		i++;
// 	}
// 	return (cwords);
// }

// int	ft_sword(char *str, char *charset, int *i, int *j)
// {
// 	while ((is_charset(str[*i], charset) == 1) && (str[*i] != '\0'))
// 	{
// 		(*i)++;
// 	}
// 	*j = *i;
// 	while ((is_charset(str[*j], charset) == 0 && str[*j] != '\0'))
// 	{
// 		(*j)++;
// 	}
// 	return (*j - *i);
// }

// void	ft_fill(char *str, int i, int j, char *tab)
// {
// 	int	k;

// 	k = 0;
// 	while (i < j)
// 	{
// 		tab[k++] = str[i++];
// 	}
// 	tab[k] = '\0';
// }

// char	**ft_split_awk(char *str, char *charset)
// {
// 	int		cwords;
// 	int		i;
// 	int		j;
// 	char	**tab;
// 	int		y;

// 	y = 0;
// 	i = 0;
// 	j = 0;
// 	cwords = ft_countwords(str, charset);
// 	tab = malloc(sizeof(char *) * (cwords + 1));
// 	if (tab == NULL)
// 		return (NULL);
// 	while (y < cwords)
// 	{
// 		ft_sword(str, charset, &i, &j);
// 		tab[y] = malloc(sizeof(char) * ((j - i) + 1));
// 		if (tab[y] == NULL)
// 			return (NULL);
// 		ft_fill(str, i, j, tab[y]);
// 		i = j;
// 		y++;
// 	}
// 	tab[y] = NULL;
// 	return (tab);
// }
// int main(int argc, char **argv)
// {
// 	int y;
// 	char **splitted;

// 	y = 0;
// 	splitted = ft_split_awk(argv[1], "'");
// 	while (splitted[y])
// 	{
// 		printf("%s\n", splitted[y]);
// 		y++;
// 	}
// 	return(0);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "pipex.h"

// static char	**ft_free(char ***tab, int x)
// {
// 	while (x >= 0)
// 	{
// 		free ((*tab)[x]);
// 		x--;
// 	}
// 	free (*tab);
// 	return (NULL);
// }

// static int	ft_nbwords(char const *s, char c)
// {
// 	int	nbwords;
// 	int	a;

// 	a = 0;
// 	nbwords = 0;
// 	while (s[a])
// 	{
// 		if (s[a] != c
// 			&& (s[a + 1] == c || s[a + 1] == '\0'))
// 		{
// 			nbwords++;
// 			a++;
// 		}
// 		else
// 			a++;
// 	}
// 	return (nbwords);
// }

// static void	ft_length(char const *s, char c, int *i, int *j)
// {
// 	while (s[*i] == c)
// 		(*i)++;
// 	*j = *i;
// 	while (s[*j] != c && s[*j] != '\0')
// 		(*j)++;
// }

// static char	*ft_fill(const char *s, char *tab, int i, int j)
// {
// 	int	k;

// 	k = 0;
// 	while (i < j)
// 	{
// 		tab[k] = s[i];
// 		k++;
// 		i++;
// 	}
// 	tab[k] = '\0';
// 	return (tab);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		i;
// 	int		j;
// 	int		m;
// 	int		nbwords;

// 	i = 0;
// 	j = 0;
// 	m = 0;
// 	nbwords = ft_nbwords(s, c);
// 	tab = malloc(sizeof(char *) * (nbwords + 1));
// 	if (!tab)
// 		return (NULL);
// 	while (m < nbwords)
// 	{
// 		ft_length(s, c, &i, &j);
// 		tab[m] = malloc(sizeof(char) * (j - i) + 1);
// 		if (!tab[m])
// 			return (ft_free(&tab, m));
// 		ft_fill(s, tab[m], i, j);
// 		i = j;
// 		m++;
// 	}
// 	tab[m] = NULL;
// 	return (tab);
// }


// size_t	ft_strlen(const char *s)
// {
// 	int	y;

// 	y = 0;
// 	while (s[y])
// 		y++;
// 	return (y);
// }

// int main(int argc, char **argv)
// {
// 	int y;
// 	int i;
// 	int	btw_quote;

// 	btw_quote = 0;
// 	y = 0;
// 	i = 0;
// 	while (argv[1][y])
// 	{
// 		if (!btw_quote && (argv[1][y] != '\''))
// 			y++;
// 		else if (argv[1][y] == '\'')
// 		{
// 			btw_quote = !btw_quote;
// 			argv[1][y] = argv[1][y + 1];
// 			y++;
// 			y++;
// 		}
// 		else if (btw_quote)
// 		{
// 			if (argv[1][y] == ' ')
// 				argv[1][y] = 1;
// 			y++;
// 		}
// 	}
// 	printf("%s\n", argv[1]);
// 	char ** splitted = ft_split(argv[1], ' ');
// 	int a = 0;
// 	int z;
// 	while (splitted[a])
// 	{
// 		z = 0;
// 		while (splitted[a][z])
// 		{
// 			if (splitted[a][z] == 1)
// 				splitted[a][z] = ' ';
// 			z++;
// 		} 
// 		a++;
// 	}
// 	a = 0;
// 	while (splitted[a])
// 	{
// 		printf("%s\n", splitted[a]);
// 		a++;
// 	}

// 	return (0);
// }

int	found_quote(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '\'')
			return (1);
		else
			a++;
	}
	return (0);
}

// void	extract_args(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
// {
// 	char	*str;

// 	str = replacing(data, cmd, pipes, y);
// }

// char	*replacing(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
// {
// 	int 	a;
// 	char	*str;
// 	int		btw_quote;
// 	int		i;

// 	i = 0;
// 	btw_quote = 0;
// 	a = 0;
// 	str = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
// 	while (data->argv[y])
// 	{
// 		if (!btw_quote && (argv[y][a] != '\''))
// 		{
// 			str[i] = argv[y][a];
// 			y++;
// 			i++;
// 		}
// 		else if (argv[y][a] == '\'')
// 		{
// 			btw_quote = !btw_quote;
// 			y++;
// 		}
// 		else if (btw_quote)
// 		{
// 			if (argv[y][a] == ' ')
// 				str[i] = 1;
// 			else
// 				str[i] = argv[y][a];
// 			i++;
// 			y++;
// 		}
// 		str[i] = '\0';
// 	}
// }

// void	replacing2(char *str, int y, int i, int *btw_quote)
// {
// 		if (argv[y][a] == '\'')
// 		{
// 			btw_quote = !btw_quote;
// 			y++;
// 		}
// 		else if (btw_quote)
// 		{
// 			if (argv[y][a] == ' ')
// 				str[i] = 1;
// 			else
// 				str[i] = argv[y][a];
// 			i++;
// 			y++;
// 		}
// 		str[i] = '\0';
// }

// static int	is_set(char c, char const *set)
// {
// 	int	y;

// 	y = 0;
// 	while (set[y])
// 	{
// 		if (set[y] == c)
// 			return (1);
// 		else
// 			y++;
// 	}
// 	return (0);
// }

// static void	ft_create_newstr(const char *s1, char *new_str, int i, int j)
// {
// 	int	y;

// 	y = 0;
// 	while (i <= j)
// 	{
// 		new_str[y] = s1[i];
// 		i++;
// 		y++;
// 	}
// 	new_str[y] = '\0';
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		j;
// 	char	*new_str;

// 	j = 0;
// 	i = 0;
// 	while (s1[i] && is_set(s1[i], set) == 1)
// 	{
// 		i++;
// 	}
// 	while (s1[j])
// 		j++;
// 	j = j - 1;
// 	while (is_set(s1[j], set) == 1 && j > 0)
// 		j--;
// 	if (i > j)
// 		return (ft_strdup(""));
// 	new_str = malloc(sizeof(char) * (j - i + 1) + 1);
// 	if (!new_str)
// 		return (0);
// 	ft_create_newstr(s1, new_str, i, j);
// 	return (new_str);
// }

void masquage(t_data *data, int y)
{
	int a;
	int	btw_quote;

	btw_quote = 0;
	a = 0;
	while (data->argv[y][a])
	{
		if (!btw_quote && (data->argv[y][a] != '\''))
			a++;
		else if (data->argv[y][a] == '\'')
		{
			btw_quote = !btw_quote;
			a++;
		}
		else if (btw_quote)
		{
			if (data->argv[y][a] == ' ')
				data->argv[y][a] = 1;
			a++;
		}
	}
}

void	demasquage(t_paths *cmd, int y)
{
	int		a;
	char	*tmp;

	y = 0;
	while (cmd->args[y])
	{
		a = 0;
		if (found_quote(cmd->args[y]))
		{
			tmp = cmd->args[y];
			cmd->args[y] = ft_strtrim(cmd->args[y], "'");
			free(tmp);
			while (cmd->args[y][a])
			{
				if (cmd->args[y][a] == 1)
					cmd->args[y][a] = ' ';
				a++;
			}
		}
		printf("%s\n", cmd->args[y]);
		y++;
	}
}

void	extract_args(t_data *data, t_paths *cmd, t_pipes *pipes, int y)
{
	int a;

	a = 0;
	printf("je suis la\n");
	masquage(data, y);
	cmd->args = ft_split(data->argv[y], ' ');
	while (cmd->args[a])
	{
		printf("%s\n", cmd->args[a]);
		a++;
	}
	// if (!cmd->args)
	// {
	// 	ft_free_pipes(pipes, data);
	// 	ft_free_paths(cmd);
	// 	ft_free_data(data);
	// }
	demasquage(cmd, y);
	while (cmd->args[a])
	{
		printf("%s\n", cmd->args[a]);
		a++;
	}
}
