/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 05:00:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/20 01:59:10 by mchemakh         ###   ########.fr       */
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
	int				size_y;
	int				size_x;
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

	char			**color;
	char			*altitude;
	int				fd;

}					t_parse;

typedef struct		s_calc
{
	double a;
	double b;
	int x;
	int y;
	double x0;
	double y0;
	double x1;
	double y1;
	int dx;
	int dy;
	unsigned int color;
}					t_calc;

typedef struct		s_stock
{
	int x;
	double x0;
	double x1;
	int y;
	double y0;
	double y1;
}					t_stock;

int		ft_display(t_env *env);
int		ft_event(t_env *env);
int		ft_window(t_env *env);

void	ft_clear_env(t_env *env);
void	ft_clear_parser(t_parse *parser);

void	ft_error_mlx_ptr(t_env *env);
void	ft_error_win_ptr(t_env *env);

void	ft_store_altitude(t_parse *parser, t_env *env);
void	ft_store_color(t_parse *parser, t_env *env, int *i);

t_stock	ft_init_stock(int x0, int x1, int y0, int y1);
t_calc	ft_init_calcul();
t_env	ft_init_env();
t_parse	*ft_init_parser();

int		ft_parser(t_parse *parser, t_env *env, char **argv);

char	*ft_get_file(int fd);

#endif
