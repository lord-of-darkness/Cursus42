/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:07:39 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:53:34 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_tetr(t_list *pos, int cur, int i, int j)
{
	int x;
	int y;

	x = 0;
	while (x < (*g_tetr[cur]).h)
	{
		y = 0;
		while (y < (*g_tetr[cur]).w)
		{
			if ((*g_tetr[cur]).tab[x][y] == 'A' + cur)
				pos->tab[i + x][j + y] = 'A' + cur;
			y++;
		}
		x++;
	}
	g_used_tetr[cur] = 1;
}

void	ft_delete_tetr(t_list *pos, int cur)
{
	int i;
	int j;

	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			if (pos->tab[i][j] == 'A' + cur)
				pos->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	g_used_tetr[cur] = 0;
}

void	ft_initial_tetr(char ***pos, int size)
{
	int i;
	int j;

	g_used_tetr = (int*)malloc(sizeof(int) * g_tetr_count);
	*pos = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < g_tetr_count)
		g_used_tetr[i++] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		(*pos)[i] = (char*)malloc(sizeof(char) * size);
		while (j < size)
		{
			(*pos)[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_solve(t_list *pos, int cur)
{
	int i;
	int j;

	if (cur == g_tetr_count)
		return (1);
	if (ft_initial_pos(cur))
		return (ft_solve(pos, ft_next_tetr()));
	i = 0;
	while (i <= g_map_size)
	{
		j = 0;
		while (j <= g_map_size)
		{
			if (ft_check_space(pos, cur, i, j))
			{
				ft_put_tetr(pos, cur, i, j);
				if (ft_solve(pos, ft_next_tetr()))
					return (1);
				ft_delete_tetr(pos, cur);
			}
			j++;
		}
		i++;
	}
	return (0);
}
