/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/26 04:37:20 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_format_grid(t_env *env)
{
	double	size;

	size = 0;
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
//		printf("adj_X[%.4f] - adj_y[%.4f]\n", env->adj_x, env->adj_y);
	}
	return (0);
}

static int		ft_segment(t_env *env, t_calc calc)
{
	if (calc.y0 > calc.y1)
		calc.y = 0;
	else
		calc.y = calc.y0;
	while (calc.y < calc.y1)
	{
		if (calc.x0 > calc.x1)
			calc.x = 0;
		else
			calc.x = calc.x0;
		while (calc.x < calc.x1)
		{
			calc.a = (calc.y0 - calc.y1) / (calc.x0 - calc.x1);
			calc.b = calc.y1 - (calc.a * calc.x1);
			if ((calc.y = calc.a * calc.x + calc.b) > 0)
			{
				mlx_pixel_put(env->mlx, env->win, calc.x, calc.y, calc.color);
			}
			calc.x++;
		}
		calc.y++;
	}
	return (0);
}

static void	ft_vertical(t_env *env)
{
	int x;
	int y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if (x == 1920 / 2)
				mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

static void	ft_horizontal(t_env *env)
{
	int x;
	int y = 0;
	while (y < 1920)
	{
		x = 0;
		while (x < 1080)
		{
			if (x == 1080 / 2)
			mlx_pixel_put(env->mlx, env->win, y, x, 0xFF0000);
			x++;
		}
		y++;
	}
}

static int		ft_fill(t_env *env, t_calc calc, t_stock stock)
{
	double	i;
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	adj;

	adj = 1;
	if (env->adj_y < 1 && env->adj_y > 0)
		adj = env->adj_y;
	else if (env->adj_y > 1)
		adj = env->adj_x;
	else
		adj = 1;
	i = 0;
	while (i * 16 < ((env->width / 4) * adj)) // '\'
	{
		x0 = env->width / 4 + (i * 16);
		x1 = env->width / 2 + (i * 16);
		y0 = env->height / 2 - (i * 9);
		y1 = 3 * env->height / 4 - (i * 9);

		stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
		i += (double)((((env->width / 4) * adj) / 16) / env->size_y);
	}
	i = 0;
	while (i * 16 < (env->width / 4))// '/'
	{
		x0 = env->width / 2 - (i * 16);
		x1 = (3 * (env->width / 4) + (env->width / 4 / env->size_x * env->size_y)) - (i * 16) ;
//		x1 = 3 * (env->width / 4) - (i * 16) ;
		y0 = 3 * (env->height / 4) - (i * 9);
		y1 = env->height / 2 + (env->height / 4 / env->size_x * (env->size_x - env->size_y)) - (i * 9);
//		y1 = (env->height / 2) - (i * 9);

		stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
		i += (double)(((env->width / 4) / 16) / env->size_x);
	}
	ft_vertical(env);
	ft_horizontal(env);
	return (0);
}

static int		ft_grille(t_env *env, t_calc calc, t_stock stock)
{
	ft_format_grid(env);
	ft_fill(env, calc, stock);
	return (0);
}

int				ft_display(t_env *env)
{
	t_calc		calc;
	t_stock		stock;

	stock = ft_init_stock(0, 0, 0, 0);
	calc = ft_init_calcul(stock);
	ft_grille(env, calc, stock);
	return (0);
}
