/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:08:48 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/23 09:53:04 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(unsigned int n, char *base)
{
	if (n == 0)
		return ;
	ft_putnbr_base(n / 16, base);
	write(1, &base[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = -1;
	while (str[++i])
	{
		c = str[i];
		if ((c >= 0 && c <= 31) || c >= 127)
		{
			write(1, "\\", 2);
			if (str[i] < 16)
				write(1, "0", 1);
			ft_putnbr_base(c, "0123456789abcdef");
		}
		else
			write(1, &str[i], 1);
	}
}
