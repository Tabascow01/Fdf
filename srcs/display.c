/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/19 05:02:41 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int		ft_border(t_env *env, t_calc calc, t_stock stock)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = env->width / 2;
	x1 = env->width - (env->width / 4);
	y0 = env->height / 4;
	y1 = env->height / 2;

	stock = ft_init_stock(x0, x1, y0, y1);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);

	x0 = env->width / 4;
	x1 = calc.x0;
	y0 = env->height / 2;
	y1 = calc.y0;

	stock = ft_init_stock(x0, x1, y0, y1);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);

	x0 = calc.x0;
	x1 = env->width / 2;
	y0 = calc.y0;
	y1 = 3 * env->height / 4;

	stock = ft_init_stock(x0, x1, y0, y1);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);

	x0 = calc.x1;
	x1 = 3 * (env->width / 4);
	y0 = calc.y1;
	y1 = env->height / 2;

	stock = ft_init_stock(x0, x1, y0, y1);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);
	return (0);
}

static int		ft_fill(t_env *env, t_calc calc, t_stock stock)
{
	float	i;
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	i = 0;
	while (i * 16 < env->width / 4)
	{
		x0 = env->width / 4 + (i * 16);
		x1 = env->width / 2 + (i * 16);
		y0 = env->height / 2 - (i * 9);
		y1 = 3 * env->height / 4 - (i * 9);

		stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
		i += (float)((env->width / 4) / 16) / env->size_y;
	}
	i = 0;
	while (i * 16 < env->width / 4)
	{
		x0 = env->width / 2 - (i * 16);
		x1 = 3 * (env->width / 4) - (i * 16);
		y0 = 3 * env->height / 4 - (i * 9);
		y1 = env->height / 2 - (i * 9);

		stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
		i += (float)((env->width / 4) / 16) / env->size_x;
	}
	return (0);
}
static int		ft_grille(t_env *env, t_calc calc, t_stock stock)
{
	ft_border(env, calc, stock);
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
