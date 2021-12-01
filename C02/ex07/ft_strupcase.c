/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:31:03 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/12 16:49:02 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if ((c > 'z' || c < 'a') && (c > 'Z' || c < 'A'))
		return (0);
	return (1);
}

int	ft_char_is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (ft_char_is_alpha(c) == 1)
			if (ft_char_is_lowercase(c) == 1)
				str[i] += 'A' - 'a';
		i++;
	}
	return (str);
}
