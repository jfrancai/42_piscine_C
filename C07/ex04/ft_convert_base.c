/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:47:38 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/28 11:25:12 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_first_value(char *base, char *s);

char	*ft_strcat(char *dest, char c)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i] = c;
	dest[i + 1] = '\0';
	return (dest);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_recursive(long n, long base_size, char *base, char *result)
{
	if (n < 0)
	{
		n = -n;
		ft_strcat(result, '-');
	}
	if (n == 0)
		return ;
	ft_recursive(n / base_size, base_size, base, result);
	ft_strcat(result, base[n % base_size]);
}

int	ft_putnbr_base(int nbr, char *base, char *result)
{
	long	base_size;

	base_size = check_base(base);
	if (nbr == 0)
	{
		ft_strcat(result, base[0]);
		return (0);
	}
	if (base_size)
	{
		ft_recursive((long)nbr, base_size, base, result);
		return (0);
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		r;
	char	*result;

	result = malloc(sizeof(char) * 40);
	result[0] = '\0';
	r = check_first_value(base_from, nbr);
	if (r != 0)
		return (NULL);
	r = ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, result);
	if (r != 0)
		return (NULL);
	result [32] = '\0';
	return (result);
}
