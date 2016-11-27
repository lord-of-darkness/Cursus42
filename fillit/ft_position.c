/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:15:56 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:52:49 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_w(char **tab)
{
	int	i;
	int	j;
	int	pos[2];

	*pos = -1;
	*(pos + 1) = -1;
	j = -1;
	while (*pos == -1)
	{
		j++;
		i = -1;
		while (++i < 4)
			if (*(*(tab + i) + j) == 64 + g_tetr_count)
				*pos = j;
	}
	j = 4;
	while (*(pos + 1) == -1)
	{
		j--;
		i = -1;
		while (++i < 4)
			if (*(*(tab + i) + j) == 64 + g_tetr_count)
				*(pos + 1) = j;
	}
	(*(g_tetr + g_tetr_count - 1))->w = (*(pos + 1) - *pos + 1);
}

void	ft_check_h(char **tab)
{
	int i;
	int j;
	int pos[2];

	*pos = -1;
	*(pos + 1) = -1;
	i = -1;
	while (*pos == -1)
	{
		i++;
		j = -1;
		while (++j < 4)
			if (*(*(tab + i) + j) == 64 + g_tetr_count)
				*pos = i;
	}
	i = 4;
	while (*(pos + 1) == -1)
	{
		i--;
		j = -1;
		while (++j < 4)
			if (*(*(tab + i) + j) == 64 + g_tetr_count)
				*(pos + 1) = i;
	}
	(*(g_tetr + g_tetr_count - 1))->h = (*(pos + 1) - *pos + 1);
}

int		ft_next_tetr(void)
{
	int i;

	i = 0;
	while (i < g_tetr_count)
	{
		if (!g_used_tetr[i])
			return (i);
		i++;
	}
	return (g_tetr_count);
}

int		ft_check_size(int nr)
{
	G;
	return (r[nr]);
}
