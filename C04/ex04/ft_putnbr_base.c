/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:39:15 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/23 18:06:11 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

long int	check_base(char *base)
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

void	ft_recursive(long n, long base_size, char *base)
{
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n == 0)
		return ;
	ft_recursive(n / base_size, base_size, base);
	write(1, &base[n % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_size;

	base_size = check_base(base);
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (!base_size)
		return ;
	ft_recursive((long)nbr, base_size, base);
}
