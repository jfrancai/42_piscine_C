/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:40:18 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/29 10:52:11 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	count_words(char *s, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_in_charset(s[i], charset))
			i++;
		if (s[i] && !is_in_charset(s[i], charset))
		{
			count++;
			while (s[i] && !is_in_charset(s[i], charset))
				i++;
		}
	}
	return (count);
}

int	ft_strlen(char *s, char *charset)
{
	int	i;

	i = 0;
	while (s[i] && !is_in_charset(s[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *s, char *charset)
{
	char	**tab;
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_words(s, charset) + 1));
	while (s[i])
	{
		while (s[i] && is_in_charset(s[i], charset))
			i++;
		if (s[i] && !is_in_charset(s[i], charset))
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * ft_strlen(s + i, charset) + 1);
			while (s[i] && !is_in_charset(s[i], charset))
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
