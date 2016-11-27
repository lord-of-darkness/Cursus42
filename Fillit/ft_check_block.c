/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:13:34 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:48:42 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_last(int *fd, char *c, short *flag)
{
	if (read(*fd, c, 1))
		*flag = 1;
	else
		*flag = 0;
	if (*c != '\n' && *flag)
		ft_error();
}

void	ft_create_map(char **temp, short *flag)
{
	*temp = (char*)malloc(sizeof(char) * 20);
	*flag = 1;
	g_tetr_count = 0;
	g_tetr = NULL;
}

int		ft_check_block(char **tab, int i, int j, short *flag)
{
	int c;

	c = 0;
	if (i - 1 >= 0)
		if (*(*(tab + i - 1) + j) == 64 + g_tetr_count)
			c++;
	if (j - 1 >= 0)
		if (*(*(tab + i) + j - 1) == 64 + g_tetr_count)
			c++;
	if (i + 1 < 4)
		if (*(*(tab + i + 1) + j) == 64 + g_tetr_count)
			c++;
	if (j + 1 < 4)
		if (*(*(tab + i) + j + 1) == 64 + g_tetr_count)
			c++;
	if (c)
		*flag = 1;
	return (c);
}

void	ft_check_line(int *line)
{
	int		i;
	short	flag;

	flag = 0;
	i = -1;
	while (++i < 4)
	{
		if (*(line + i) > 1)
			flag = 1;
	}
	if (!flag)
		ft_error();
}
