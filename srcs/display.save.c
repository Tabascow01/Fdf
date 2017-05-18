/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/18 04:50:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_round(float x)
{
	return (int)(x + 0.5);
}

static int		ft_tracer_segment(int x, int y, t_env *env, t_calc calc)
{
	int		i;

	i = 0;
	calc.e = ((float)calc.dy) / ((float)calc.dx);
	while (i < calc.dx)
	{
		x = calc.x0 + i;
		y = ft_round(calc.y0 + calc.e * i);
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		i++;
	}
	return (0);
}

static int		ft_grille(t_env *env, t_calc calc, t_stock stock)
{
	int		i;

	// Contour grille
	stock = ft_init_stock(200, 600, 400, 800); // '\' bas
	calc = ft_init_calcul(stock);
	ft_tracer_segment(0, 0, env, calc);

	stock = ft_init_stock(600, 900, 800, 500);// '/' bas
	calc = ft_init_calcul(stock);
	ft_tracer_segment(0, 0, env, calc);

	stock = ft_init_stock(200, 500, 400, 100);// '\' haut
	calc = ft_init_calcul(stock);
	ft_tracer_segment(0, 0, env, calc);

	stock = ft_init_stock(500, 900, 100, 600);// '/' haut
	calc = ft_init_calcul(stock);
	ft_tracer_segment(0, 0, env, calc);

	// Grille interne
	i = 0;
	while (i < 300)
	{
		stock = ft_init_stock(500 - i, 900 -i, 100 + i, 600 + i);// '\'
		calc = ft_init_calcul(stock);
		ft_tracer_segment(0, 0, env, calc);
		i += 25;
	}
	i = 0;
	while (i < 400)
	{
		stock = ft_init_stock(200 + i, 500 + i, 400 + i, 100 + i);// '/'
		calc = ft_init_calcul(stock);
		ft_tracer_segment(0, 0, env, calc);
		i += 25;
	}
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
