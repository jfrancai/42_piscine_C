/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:05:38 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/20 12:28:29 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_table(int indice, int *table)
{
	int	i;
	int	mod;
	int	div;

	i = -1;
	div = indice / 10;
	mod = indice % 10;
	while (++i < indice)
		if ((table[indice] == table[i]) && (mod == i % 10 || div == i / 10))
			return (0);
	return (1);
}

void ft_print_tab(int *tab)
{
	int i;

	i = -1;
	while (++i < 10)
		printf("0 ");
	printf("\n");
}

int	*genere_table(int indice)
{
	int tab[10];
	int j;

	j = -1;
	tab[indice] = 0;
	while (tab[indice] <= 10)
	{
		if (check_table(indice, tab))
		{
			if (indice == 0)
			{
				while(++j < 10)
					ft_print_tab(tab);
				return (0);
			}
			else
				genere_table(indice + 1);
		}
		tab[indice]++;
	}
	return (0);
}

int ft_ten_queens_puzzle(void)
{
	genere_table(0);
	return (0);
}


int main()
{
	ft_ten_queens_puzzle();
}
