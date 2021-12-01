/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:47:27 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/28 08:33:18 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = 0;
		while (base[i + (++j)])
			if (base[i] == base[i + j])
				return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
	}
	return (i);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int	check_first_value(char *base, char *s)
{
	int	i;

	i = 0;
	while (s[i] <= ' ' || s[i] == '+' || s[i] == '-')
		i++;
	if (ft_is_in_base(s[i], base) == -1)
		return (-1);
	return (0);
}

int	ft_convert_base_ten(char *str, char *base, int base_len)
{
	int	i;
	int	index_in_base;
	int	nb;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		index_in_base = ft_is_in_base(str[i], base);
		if (index_in_base < 0)
			return (nb);
		nb = nb * base_len + index_in_base;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	i;

	i = -1;
	sign = 1;
	base_len = ft_check_base(base);
	if (str[0] == 0)
		return (0);
	if (base_len == 0 || base_len == 1)
		return (0);
	while (str[i] <= ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign * ft_convert_base_ten(&str[i], base, base_len));
}
