/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:19:10 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:54:14 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_col_cpy(char *temp, char **tab, int j)
{
	int v;
	int i;

	v = -1;
	i = -1;
	while (++v < 4)
	{
		*(temp + v) = *(*(tab + ++i) + j);
		*(*(tab + i) + j) = '.';
	}
}

void	ft_swap_col(void)
{
	char	**tab;
	int		i[3];
	int		k;
	char	temp[4];

	tab = (*(g_tetr + g_tetr_count - 1))->tab;
	i[1] = -1;
	k = 0;
	while (++i[1] < 4)
	{
		i[0] = -1;
		while (++i[0] < 4)
			if (*(*(tab + i[0]) + i[1]) == 64 + g_tetr_count)
			{
				ft_col_cpy(temp, tab, i[1]);
				i[2] = -1;
				while (++i[2] < 4)
					*(*(tab + i[2]) + k) = temp[i[2]];
				k++;
				break ;
			}
	}
}

void	ft_line_cpy(char *temp, char *tab)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		*(temp + i) = *(tab + i);
		*(tab + i) = '.';
	}
}

void	ft_swap_line(void)
{
	char	**tab;
	int		i[3];
	int		k;
	char	temp[4];

	tab = (*(g_tetr + g_tetr_count - 1))->tab;
	i[0] = -1;
	k = 0;
	while (++i[0] < 4)
	{
		i[1] = -1;
		while (++i[1] < 4)
			if (*(*(tab + i[0]) + i[1]) == 64 + g_tetr_count)
			{
				ft_line_cpy(temp, *(tab + i[0]));
				i[2] = -1;
				while (++i[2] < 4)
					*(*(tab + k) + i[2]) = temp[i[2]];
				k++;
				break ;
			}
	}
}
