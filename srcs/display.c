/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/09 05:23:15 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_fill(t_env *env, t_calc calc, t_stock stock)
{
	double	i;
	double	adj;

	adj = 1;
	if (env->adj_y < 1 && env->adj_y > 0)
		adj = env->adj_y;
	else if (env->adj_y > 1)
		adj = env->adj_x;
	else
		adj = 1;
	i = 0;
	ft_segment_lenght(env, &stock, 1);
//	while (i < env->height / 2)
//	{
		//stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
//		i += (double)((env->width / 2 - (env->width / 4 * 1.25)) / env->size_y);
//	}
	i = 0;
	ft_segment_lenght(env, &stock, 2);
//	while (i * 16 < (env->width / 4))// '/'
//	{
		//stock = ft_init_stock(x0, x1, y0, y1);
		calc = ft_init_calcul(stock);
		ft_segment(env, calc);
//		i += (double)(((env->width / 4) / 16) / env->size_x);
//	}

	// Fonction d'affichage echelle (experimental.c)
	ft_win_v(env);
	ft_win_h(env);
	ft_win_d1(env);
	ft_win_d2(env);
	ft_init_stock(0, 0, 0, 0); // Reset valeurs stock
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
