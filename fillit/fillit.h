/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:09:43 by ionofrei          #+#    #+#             */
/*   Updated: 2016/11/26 16:03:50 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define R r[]
# define G int	R = {2,3,4,4,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,11};

typedef struct	s_list
{
	char	**tab;
	int		h;
	int		w;
}				t_list;

int				g_tetr_count;
int				g_map_size;
int				*g_used_tetr;
t_list			**g_tetr;
void			ft_put_tetr(t_list *pos, int cur, int i, int j);
void			ft_delete_tetr(t_list *pos, int cur);
void			ft_initial_tetr(char ***pos, int size);
int				ft_solve(t_list *pos, int cur);
void			ft_show_pos(char **pos, int size);
int				ft_check_space(t_list *pos, int cur, int i, int j);
int				ft_initial_pos(int cur);
void			ft_check_file(char *file);
void			ft_extract_tetr(int fd);
void			ft_check_w(char **tab);
void			ft_check_h(char **tab);
int				ft_next_tetr(void);
int				ft_check_size(int nr);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_error(void);
void			ft_col_cpy(char *temp, char **tab, int j);
void			ft_swap_col();
void			ft_line_cpy(char *temp, char *tab);
void			ft_swap_line();
void			ft_check_tetr(char *temp);
void			ft_check_tab(char *temp);
void			ft_mem_realloc(int size);
void			ft_valid_tetr(char **tab_temp);
void			ft_check_last(int *fd, char *c, short *flag);
void			ft_create_map(char **temp, short *flag);
int				ft_check_block(char **tab, int i, int j, short *flag);
void			ft_check_line(int *line);

#endif
