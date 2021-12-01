/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:51:27 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/19 20:22:03 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	while (--power > 0)
	{
		nb *= n;
	}
	return (nb);
}

int	ft_sqrt(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	if (nb > 2147395600)
		return (0);
	result = 0;
	i = 0;
	while (result < nb)
	{
		result = ft_iterative_power(i, 2);
		if (result == nb)
			return (i);
		i++;
	}
	return (0);
}
