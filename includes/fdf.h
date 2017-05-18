/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 05:00:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/18 05:00:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>
# include "../ressources/minilibx_macos_sierra_20161017/mlx.h"
# include <stdio.h>

typedef struct		s_env
{
	char			*parser;

	int				error;

	void			*mlx;
	void			*win;

	int				height;
	int				width;
	char			*title;
}					t_env;

typedef struct		s_parse
{
	struct s_parse	*next;

	int				fd;

}					t_parse;

typedef struct		s_calc
{
	int x;
	int y;
	int x0;
	int y0;
	int x1;
	int y1;
	int dx;
	int dy;
	int deltaE;
	int	deltaNE;
	int	dp;
//	int e;
//	int	incX;
//	int	incY;
}					t_calc;

typedef struct		s_stock
{
	int x;
	int x0;
	int x1;
	int y;
	int y0;
	int y1;
	int z0;
	int z1;
	int z2;
	int z3;
}					t_stock;

int		ft_display(t_env *env);
int		ft_event(t_env *env);
int		ft_window(t_env *env);

void	ft_clear_env(t_env *env);
void	ft_clear_parser(t_parse *parser);

void	ft_error_mlx_ptr(t_env *env);
void	ft_error_win_ptr(t_env *env);

t_stock	ft_init_stock(int x0, int x1, int y0, int y1);
t_calc	ft_init_calcul();
t_env	ft_init_env();
t_parse	*ft_init_parser();

int		ft_parser(t_parse *parser, t_env *env, char **argv);

char	*ft_get_file(int fd);

#endif
