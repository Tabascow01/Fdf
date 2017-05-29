/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimental.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:49:36 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/29 04:39:42 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vertical(t_env *env)
{
	int x;
	int y = 0;
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

void	ft_horizontal(t_env *env)
{
	int x;
	int y = 0;
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
