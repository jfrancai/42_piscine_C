/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:57:01 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/14 13:30:51 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if ((c > 'z' || c < 'a') && (c > 'Z' || c < 'A'))
		return (0);
	return (1);
}

int	ft_char_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

void	ft_charlowcase(char *c)
{
	if (*c <= 'Z' && *c >= 'A')
		*c -= 'A' - 'a';
}

void	ft_charupcase(char *c)
{
	if (*c <= 'z' && *c >= 'a')
		*c += 'A' - 'a';
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_alpha(str[i]))
		{
			if (!ft_char_is_numeric(str[i - 1]))
			{
				ft_charupcase(&str[i]);
				i++;
			}
			while (ft_char_is_alpha(str[i]) == 1)
			{
				ft_charlowcase(&str[i]);
				i++;
			}
		}
		i++;
	}
	return (str);
}
