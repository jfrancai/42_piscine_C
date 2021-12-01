/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:50:02 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/12 16:51:50 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if ((c > 'z' || c < 'a') && (c > 'Z' || c < 'A'))
		return (0);
	return (1);
}

int	ft_char_is_uppercase(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (ft_char_is_alpha(c) == 1)
			if (ft_char_is_uppercase(c) == 1)
				str[i] -= 'A' - 'a';
		i++;
	}
	return (str);
}
