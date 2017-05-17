/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/17 23:55:26 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_display(t_env *env)
{
	t_calc	calc;
	
	calc = ft_init_calcul();
	calc.incrE = 2 * calc.dy;
	calc.incrNE = 2 * (calc.dy - calc.dx);
	calc.e = 2 * calc.dy - calc.dx;

	if (calc.dx > 0)
		calc.incX = 1;
	else
	{
		calc.incX = -1;
		calc.dx = -calc.dx;
	}
	if (calc.dy > 0)
		calc.incY = 1;
	else
	{
		calc.incY = -1;
		calc.dy = -calc.dy;
	}
	if (calc.dx > calc.dy)
	{
		while (calc.x <= calc.x1)
		{
			mlx_pixel_put(env->mlx, env->win, calc.x, calc.y,0xFFFFFF);
			calc.x++;
		}
		if (calc.e >= 0)
		{
			calc.y += 1;
			calc.e += calc.incrE;
		}
		else
			calc.e += calc.incrNE;
	}
	else
	{
		while (calc.y <= calc.y1)
		{
			mlx_pixel_put(env->mlx, env->win, calc.y, calc.x,0xFFFFFF);
			calc.y++;
		}
		if (calc.e >= 0)
		{
			calc.y += 1;
			calc.e += calc.incrE;
		}
		else
			calc.e += calc.incrNE;
	}
	return (0);
}
