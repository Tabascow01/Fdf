/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/18 23:44:22 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_segment(t_env *env, t_calc calc)
{
	mlx_pixel_put(env->mlx, env->win, calc.x, calc.y, calc.color);
	while (calc.x < calc.x1)
	{
		if (calc.dp <= 0)
		{
			calc.dp = calc.dp + calc.deltaE;
			calc.x++;
		}
		else
		{
			calc.dp = calc.dp + calc.deltaNE;
			calc.x++;
			calc.y++;
		}
		mlx_pixel_put(env->mlx, env->win, calc.x, calc.y, calc.color);
	}
	return (0);
}

static int		ft_grille(t_env *env, t_calc calc, t_stock stock)
{
	int		startx;
	int		starty;
	int		endx;
	int		endy;

	// init droite numero 1
	startx = env->width / 2 - (env->width / 4);
	endx = env->width - (env->width / 4);
	starty = env->height / 10;
	endy = env->height / 2 - (env->height / 6);

	// droite 1 (haut->droite)
	stock = ft_init_stock(startx, endx, starty, endy);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);


	// init droite numero 2
	startx = env->width / 10;
	endx = env->width / 2 - (env->width / 4);
	starty = env->height / 10;
	endy = env->height / 4;
	// droite 2 (haut->gauche)
	stock = ft_init_stock(startx, endx , starty, endy);
	calc = ft_init_calcul(stock);
	ft_segment(env, calc);

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
