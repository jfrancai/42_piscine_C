/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:51:10 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/10 09:04:14 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	chiffre_recursive(int nbr)
{
	int	chiffre;

	if (nbr < 10)
	{
		chiffre = nbr + 48;
		ft_putchar(chiffre);
	}
	else
	{
		chiffre_recursive(nbr / 10);
		chiffre_recursive(nbr % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		nb -= 1;
		ft_putchar('-');
		chiffre_recursive(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		chiffre_recursive(nb);
	}
	else
	{	
		chiffre_recursive(nb);
	}
}
