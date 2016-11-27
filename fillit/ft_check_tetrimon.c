/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetrimon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:12:57 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:51:59 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_tetr(char *temp)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (*(temp + i) != '\n')
				ft_error();
		}
		else if (*(temp + i) != '.' && *(temp + i) != '#')
			ft_error();
		if (*(temp + i) == '#')
		{
			count++;
			*(temp + i) = 64 + g_tetr_count;
		}
	}
	if (count != 4)
		ft_error();
	ft_check_tab(temp);
}

void	ft_check_tab(char *temp)
{
	char	**tab_temp;
	int		i;
	int		j;
	int		k;

	tab_temp = (char**)malloc(sizeof(char*) * 4);
	i = -1;
	k = -1;
	while (++i < 4)
	{
		*(tab_temp + i) = (char*)malloc(sizeof(char) * 5);
		j = -1;
		while (++j < 5)
			*(*(tab_temp + i) + j) = *(temp + ++k);
	}
	ft_valid_tetr(tab_temp);
	ft_mem_realloc(g_tetr_count);
	*(g_tetr + g_tetr_count - 1) = (t_list*)malloc(sizeof(t_list));
	(*(g_tetr + g_tetr_count - 1))->tab = tab_temp;
	ft_check_h(tab_temp);
	ft_check_w(tab_temp);
	ft_swap_col();
	ft_swap_line();
}

void	ft_mem_realloc(int size)
{
	t_list		**temp;
	int			i;

	temp = (t_list**)malloc(sizeof(t_list*) * size);
	if (g_tetr != NULL)
	{
		i = -1;
		while (++i < g_tetr_count)
			*(temp + i) = *(g_tetr + i);
		free(g_tetr);
		g_tetr = temp;
	}
	else
		g_tetr = temp;
}

void	ft_valid_tetr(char **tab_temp)
{
	int		i;
	int		j;
	short	flag;
	int		line[4];
	int		v;

	i = -1;
	v = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*(*(tab_temp + i) + j) == 64 + g_tetr_count)
			{
				flag = 0;
				line[++v] = ft_check_block(tab_temp, i, j, &flag);
				if (!flag)
					ft_error();
				ft_check_line(line);
			}
		}
	}
}
