/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:03 by fhuang            #+#    #+#             */
/*   Updated: 2016/05/13 01:13:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(const char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				n++;
		}
	}
	return (n);
}

static int	count_c(const char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] != c)
		{
			i++;
			n++;
			if (s[i] == c || s[i] == '\0')
				break ;
		}
		if (n)
			break ;
		i++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	// char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// str = (char*)s;
	// if (!(tab = (char**)ft_memalloc(sizeof(char*) * (count_str(str, c) + 1))))
	// 	return (NULL);
	// while (str[i] || (tab[j] = NULL))
	// {
	// 	str = ft_trim_c(str, c);
	// 	tab[j] = (char*)ft_memalloc(sizeof(char) * (count_c(str + i, c) + 1));
	// 	while (str[i] && str[i] == c)
	// 		i++;
	// 	if (count_c(str + i, c) > 0)
	// 	{
	// 		ft_strncpy(tab[j++], (str + i), count_c(str + i, c));
	// 		while (str[i] && str[i] != c)
	// 			i++;
	// 	}
	// }
	// return (tab);
	// char	**tab;

	if ((tab = (char**)ft_memalloc(sizeof(char*) * count_str(s, c) + 1)))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (!(tab[j] = ft_memalloc(count_c(s + i, c) + 1)))
				return (NULL);
			if (count_c(s + i, c))
				ft_strncpy(tab[j++], s + i, count_c(s + i, c));
			while (s[i] && s[i] != c)
				i++;
			i++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
