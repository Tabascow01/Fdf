/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:44:14 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/12 16:53:54 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_icarr(int nb)
{
	return (nb * nb);
}

double	ft_dcarr(double nb)
{
	return (nb * nb);
}

double	ft_calc_percent(t_env *env)
{
	double	percent;

	percent = 0.0;
	if (env->size_x > env->size_y)
		percent = (env->size_x - env->size_y) / env->size_x;
	else
		percent = (env->size_y - env->size_x) / env->size_y;
	return (percent);
}

int		ft_segment(t_env *env, t_calc calc)
{
	double	x0tmp;
	double	x1tmp;
	double	y0tmp;
	double	y1tmp;

	if (calc.y0 > calc.y1)
	{
		y0tmp = calc.y1;
		y1tmp = calc.y0;
	}
	else
	{
		y0tmp = calc.y0;
		y1tmp = calc.y1;
	}
	while (y0tmp < y1tmp)
	{
		if (calc.x0 > calc.x1)
		{
			x0tmp = calc.x1;
			x1tmp = calc.x0;
		}
		else
		{
			x0tmp = calc.x0;
			x1tmp = calc.x1;
		}
		while (x0tmp < x1tmp)
		{
			calc.a = (calc.y0 - calc.y1) / (calc.x0 - calc.x1);
			calc.b = calc.y1 - (calc.a * calc.x1);
			if (y0tmp == (int)(calc.a * x0tmp + calc.b))
				mlx_pixel_put(env->mlx, env->win, x0tmp, y0tmp, calc.color);
			x0tmp++;
		}
		y0tmp++;
	}
	return (0);
}

int		ft_format_grid(t_env *env)
{
	double	size;

	size = 0;
	ft_counter_y(env);
	ft_counter_x(env);
	printf("x[%.2f]\ny[%.2f]\n",env->size_x, env->size_y);
	if (env->size_y == env->size_x)
	{
		env->adj_x = 1;
		env->adj_y = 1;
		return (1);
	}
	else
	{
		size = env->size_y * env->size_x;
		while (size >= 10)
			size /= 10;
		if (size > 0)
		{
			if (env->size_x > env->size_y)
			{
				env->diff_y = env->size_x * (env->size_x - env->size_y);
				env->diff_x = env->size_x * env->size_y;
				env->adj_x = (double)(env->size_x / env->size_y);
				env->adj_y = (double)(env->size_y / env->size_x);
			}
			else
			{
				env->diff_y = env->size_y * (env->size_y - env->size_x);
				env->diff_x = env->size_y * env->size_x;
				env->adj_x = (double)(env->size_y / env->size_x);
				env->adj_y = (double)(env->size_x / env->size_y);
			}
		}
	}
	return (0);
}

int				ft_window_iscase(t_env *env)
{
	if (env->height == env->width)
		return (1);
	return (0);
}

static void		ft_calc_length(t_env *env, t_stock *stock, int d)
{
	t_len o_len;

	if ((env->diff = ft_calc_percent(env)) < 1)
	{
		env->diff_x = env->diff / 2;
		env->diff_y = env->diff / 2;
	}
	else
	{
		env->diff = 1;
		env->diff_x = 1;
		env->diff_y = 1;
	}
	ft_calc_percent(env);
	stock->x0 = env->width / 2;
	stock->y0 = env->height / 4;
	if (ft_window_iscase(env))
	{
		if (env->size_x == env->size_y)
			o_len = ft_init_len(env, 1.1, d);
		else if (env->size_x < env->size_y)
			o_len = ft_init_len(env, 1.2, d);
		else
			o_len = ft_init_len(env, 1.3, d);
	}
	else if (env->width > env->height)
	{
		if (env->size_x == env->size_y)
			o_len = ft_init_len(env, 2.1, d);
		else if (env->size_x < env->size_y)
			o_len = ft_init_len(env, 2.2, d);
		else
			o_len = ft_init_len(env, 2.3, d);
	}
	else
	{
		stock->x0 = env->width / 2;
		stock->y0 = env->height / 2 - ((env->height / 4 * 1.2) * (env->width / env->height));
		if (env->size_x == env->size_y)
			o_len = ft_init_len(env, 3.1, d);
		else if (env->size_x < env->size_y)
			o_len = ft_init_len(env, 3.2, d);
		else
			o_len = ft_init_len(env, 3.3, d);
	}
	ft_o_coord(&o_len, stock);
//	printf("diff[%.2f] - diff_y[%.2f] - diff_x[%.2f]\n", env->diff, env->diff_y, env->diff_x);
	printf("x0[%.2f] - y0[%.2f]\nx1[%.2f] - y1[%.2f]\n",stock->x0, stock->y0, stock->x1, stock->y1);
}

void			ft_segment_lenght(t_env *env, t_stock *stock, int d)
{
	if (ft_window_iscase(env))			// Window carre
	{
		if (env->size_x == env->size_y)	// map carre
			ft_calc_length(env, stock, d);
		else							// map rectangle
			ft_calc_length(env, stock, d);
	}
	else if (env->width > env->height)	// Window rectangle
	{
		if (env->size_x == env->size_y)	// map carre
			ft_calc_length(env, stock, d);
		else							// map rectangle
			ft_calc_length(env, stock, d);
	}
	else
	{
		if (env->size_x == env->size_y)	// map carre
			ft_calc_length(env, stock, d);
		else							// map rectangle
			ft_calc_length(env, stock, d);
	}
}
