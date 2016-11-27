/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:14:15 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:44:02 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	ft_extract_tetr(fd);
}

void	ft_extract_tetr(int fd)
{
	char	*temp;
	char	c;
	short	flag;

	ft_create_map(&temp, &flag);
	while (1)
	{
		if ((read(fd, temp, 20)) != 20)
		{
			if (flag == 0)
				break ;
			else
				ft_error();
		}
		else
		{
			flag = 1;
			g_tetr_count++;
			if (g_tetr_count > 26)
				ft_error();
			ft_check_tetr(temp);
		}
		ft_check_last(&fd, &c, &flag);
	}
	free(temp);
}
