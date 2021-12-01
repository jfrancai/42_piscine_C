/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:08:55 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/09 18:12:45 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	affichage(int a, int b, int c)
{
	a += 48;
	b += 48;
	c += 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!((a == 55 && b == 56) && c == 57))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (i < 10)
	{
		i++;
		j = i;
		while (j < 9)
		{
			j++;
			k = j;
			while (k < 9)
			{
				k++;
				affichage(i, j, k);
			}
		}
	}
}
