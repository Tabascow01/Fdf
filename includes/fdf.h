/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 05:00:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/14 16:37:49 by mchemakh         ###   ########.fr       */
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
	double			size_y;
	double			size_x;
	int				error;

	void			*mlx;
	void			*win;

	double			height;
	double			width;
	char			*title;
	int				winform;

	double			adj_x;
	double			adj_y;
	double			diff_y;
	double			diff_x;
	double			diff;
	double			len_max;
}					t_env;

typedef struct		s_parse
{
	struct s_parse	*next;

	char			**color;
	char			**altitude;
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
	double dx;
	double dy;
	unsigned int color;
}					t_calc;

typedef struct		s_stock
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	old_x0;
	double	old_y0;
	double	old_x1;
	double	old_y1;
}					t_stock;

void	ft_store_old_coord(t_stock *stock);

void	ft_len_max(t_env *env);

void	ft_scalling_case_window(t_env *env, t_stock *stock, int d);
void	ft_scalling_rec_inv_window(t_env *env, t_stock *stock, int d);
void	ft_scalling_rec_window(t_env *env, t_stock *stock, int d);

void	ft_win_form1_d1(t_env *env, t_stock *stock, double win_form);
void	ft_win_form2_d1(t_env *env, t_stock *stock, double win_form);
void	ft_win_form3_d1(t_env *env, t_stock *stock, double win_form);

void	ft_win_form1_d2(t_env *env, t_stock *stock, double win_form);
void	ft_win_form2_d2(t_env *env, t_stock *stock, double win_form);
void	ft_win_form3_d2(t_env *env, t_stock *stock, double win_form);

void	ft_segment_lenght(t_env *env, t_stock *stock, int d);

void	ft_win_d1(t_env *env);
void	ft_win_d2(t_env *env);
void	ft_win_h(t_env *env);
void	ft_win_v(t_env *env);

int		ft_counter_y(t_env *env);
int		ft_counter_x(t_env *env);

int		ft_display(t_env *env);
int		ft_event(t_env *env);
int		ft_window(t_env *env);

int		ft_segment(t_env *env, t_calc calc);
int		ft_format_grid(t_env *env);

void	ft_clear_env(t_env *env);
void	ft_clear_parser(t_parse *parser);

void	ft_test_leaks(); // TO REMOVE

void	ft_error_list();
void	ft_error_usage();
void	ft_error_parser(t_env *env);
void	ft_error_mlx_ptr(t_env *env);
void	ft_error_win_ptr(t_env *env);

char	**ft_store_altitude(t_env *env, t_parse *parser);
char	*ft_store_color(t_env *env, int *i);

void	ft_init_len(t_env *env, t_stock *stock, double win_form, int d);
t_stock	ft_init_stock(double x0, double x1, double y0, double y1);
t_calc	ft_init_calcul();
t_env	ft_init_env();
t_parse	*ft_init_parser();

int		ft_parser(t_env *env, char **argv);

char	*ft_get_file(int fd);

#endif
