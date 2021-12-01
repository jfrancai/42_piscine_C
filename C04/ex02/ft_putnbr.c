/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:54:55 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/15 08:38:16 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursive(int nb)
{
	long int	n;

	n = (long int)nb;
	if (n == 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_recursive(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
		ft_recursive(nb);
}
