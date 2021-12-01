/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:01:26 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/14 09:03:39 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	compteur;

	compteur = 0;
	while (*(str + compteur) != '\0')
		compteur++;
	return (compteur);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len_str;
	int	len_to_find;

	i = 0;
	len_str = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (i < (len_str - len_to_find) + 1)
	{
		if (ft_strncmp(to_find, &str[i], len_to_find - 1) == 0)
			return (str + i);
		i++;
	}
	return (0);
}
