/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 22:06:20 by smortier          #+#    #+#             */
/*   Updated: 2018/06/10 13:19:46 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		ft_count_words(char *str)
{
	int		i;
	int		count_w;

	i = 0;
	count_w = 0;
	while (str[i])
	{
		while (!char_is_sep(str[i]) && str[i])
		{
			i++;
			if (char_is_sep(str[i]) || str[i] == '\0')
			{
				count_w++;
			}
		}
		if (char_is_sep(str[i]) && str[i])
			i++;
	}
	return (count_w);
}

void	malloc_all_tab(char **tab, char *str)
{
	int		c_m;
	int		i;
	int		compteur_tab;

	compteur_tab = 0;
	i = 0;
	while (str[i])
	{
		c_m = 0;
		while (!char_is_sep(str[i]) && str[i])
		{
			c_m += 1;
			i++;
			if (char_is_sep(str[i]) || str[i] == '\0')
			{
				(tab[compteur_tab]) = (char *)malloc(sizeof(char) * c_m + 1);
				compteur_tab += 1;
			}
		}
		if (char_is_sep(str[i]))
			i++;
	}
}

void	fill_tab(int count_w, char *str, char **tab)
{
	int		c_m;
	int		i;

	count_w = 0;
	i = 0;
	while (str[i])
	{
		c_m = 0;
		while (!char_is_sep(str[i]) && str[i])
		{
			(tab[count_w])[c_m] = str[i];
			c_m += 1;
			i++;
			if (str[i] == '\0' || char_is_sep(str[i]))
			{
				(tab[count_w])[c_m] = '\0';
				count_w += 1;
			}
		}
		if (char_is_sep(str[i]))
			i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	int		count_w;
	char	**tab;

	count_w = ft_count_words(str);
	tab = (char **)malloc(sizeof(char *) * (count_w + 1));
	tab[count_w] = 0;
	malloc_all_tab(tab, str);
	fill_tab(count_w, str, tab);
	return (tab);
}
