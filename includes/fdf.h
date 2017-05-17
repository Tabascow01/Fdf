/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 05:00:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/17 23:54:32 by mchemakh         ###   ########.fr       */
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
	int incrE;
	int	incrNE;
	int	e;
	int	incX;
	int	incY;
}					t_calc;

int		ft_display(t_env *env);
int		ft_event(t_env *env);
int		ft_window(t_env *env);

void	ft_clear_env(t_env *env);
void	ft_clear_parser(t_parse *parser);

void	ft_error_mlx_ptr(t_env *env);
void	ft_error_win_ptr(t_env *env);

t_calc	ft_init_calcul();
t_env	ft_init_env();
t_parse	*ft_init_parser();

int		ft_parser(t_parse *parser, t_env *env, char **argv);

char	*ft_get_file(int fd);

#endif
