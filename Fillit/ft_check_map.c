/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:09:14 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:51:05 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_show_pos(char **pos, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(pos[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_check_space(t_list *pos, int cur, int i, int j)
{
	int x;
	int y;

	x = 0;
	while (x < (*g_tetr[cur]).h)
	{
		if (x + i == g_map_size)
			return (0);
		y = 0;
		while (y < (*g_tetr[cur]).w)
		{
			if (j + y == g_map_size)
				return (0);
			if ((*g_tetr[cur]).tab[x][y] != '.' &&
					pos->tab[i + x][j + y] != '.')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_initial_pos(int cur)
{
	return (g_used_tetr[cur] == 1);
}
