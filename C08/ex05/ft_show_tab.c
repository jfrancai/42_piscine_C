/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:47:22 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/30 16:01:34 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, s + i, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str != '\0')
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
	}
}
