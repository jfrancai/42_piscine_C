/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:51:12 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/23 18:39:36 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_convert_base(char *str, char *base, int base_len)
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
	return (sign * ft_convert_base(&str[i], base, base_len));
}
