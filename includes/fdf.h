/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 05:00:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/11 00:31:29 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>
# include "../ressources/minilibx_macos_sierra_20161017/mlx.h"
# include <stdio.h>

typedef struct		s_map
{
	struct s_map	*next;
	struct s_map	*first;
	struct s_map	*prev;

	char			*map_str;

	int				*map_int;
	int				error;

	void			*mlx_ptr;
	void			*mlx_win;

}					t_map;

typedef struct		s_read
{
	struct s_read	*next;

	int				fd;

}					t_read;
/*
typedef struct		s_math
{
	struct s_math	*next;

	int				*x;
	int				*y;
}					t_math;
*/

void	ft_event(t_map *lst);
void	ft_window(t_map *lst);

void	ft_clear_lst(t_map *lst);
void	ft_clear_lst_rd(t_read *lst_rd);

t_map	*ft_init_lst();
t_read	*ft_init_lst_rd();

int		ft_parser(t_read *lst_rd, t_map *lst, char **argv);

char	*ft_get_file(int fd);

#endif
