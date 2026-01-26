/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:24:52 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/25 18:13:00 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	y;

	y = 0;
	while ((s1[y] || s2[y]) && y < n)
	{
		if (s1[y] != s2[y])
			return ((unsigned char)(s1[y]) - (unsigned char)(s2[y]));
		else
			y++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	y;

	y = 0;
	while (s[y])
	{
		if (s[y] == (char)c)
			return ((char *)(s + y));
		else
			y++;
	}
	if (s[y] == (char)c)
		return ((char *)(s + y));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		y;
	char	*new_str;

	a = 0;
	y = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[a])
	{
		new_str[y] = s1[a];
		a++;
		y++;
	}
	a = 0;
	while (s2[a])
	{
		new_str[y] = s2[a];
		a++;
		y++;
	}
	new_str[y] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	return (y);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	y;

	y = 0;
	while (s[y])
	{
		ft_putchar_fd(s[y], fd);
		y++;
	}
}
