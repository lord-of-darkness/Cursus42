/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:16:26 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:54:56 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_list *pos;

	if (ac != 2)
	{
		ft_putstr("NO file\n");
		return (1);
	}
	pos = (t_list*)malloc(sizeof(t_list));
	ft_check_file(*(av + 1));
	g_map_size = ft_check_size(g_tetr_count - 1);
	while (1)
	{
		ft_initial_tetr(&(pos->tab), g_map_size);
		if (ft_solve(pos, ft_next_tetr()))
		{
			ft_show_pos(pos->tab, g_map_size);
			break ;
		}
		g_map_size++;
	}
	return (0);
}
