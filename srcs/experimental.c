/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimental.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:49:36 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/09 05:18:24 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_v(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			if (x == env->width / 2)
				mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	ft_win_h(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->width)
	{
		x = 0;
		while (x < env->height)
		{
			if (x == env->height / 2)
				mlx_pixel_put(env->mlx, env->win, y, x, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	ft_win_d1(t_env *env)
{
	t_stock	stock;
	t_calc	calc;

	stock = ft_init_stock(0, env->width, 0, env->height);
	calc = ft_init_calcul(stock);
	calc.color = 0xFF6400;
	ft_segment(env, calc);
	calc.color = 0xFFFFFF;
}


void	ft_win_d2(t_env *env)
{
	t_stock	stock;
	t_calc	calc;

	stock = ft_init_stock(env->width, 0, 0, env->height);
	calc = ft_init_calcul(stock);
	calc.color = 0xFF6400;
	ft_segment(env, calc);
	calc.color = 0xFFFFFF;
}

