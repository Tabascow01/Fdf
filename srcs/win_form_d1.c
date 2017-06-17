/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_form_d1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:14:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/14 16:49:29 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_form1_d1(t_env *env, t_stock  *stock, double win_form)
{
	if (win_form == 1.1)
	{
		stock->x1 = env->width - (env->width / 8) * 0.8;
		stock->y1 = env->height / 2;
	}
	if (win_form == 1.2)
	{
		stock->x0 = round(env->width / 2 + (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round(env->width / 2 - ((env->width / 4 * 1.2) - env->width / 4 * 1.2 * env->diff_x));
		stock->y1 = round(env->height / 2 + (env->height / 4) * env->diff_y);
	}
	if (win_form == 1.3)
	{
		stock->x0 = round(env->width / 2 - (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round(env->width / 2 + ((env->width / 4 * 1.2) - (env->width / 4 * 1.2 * env->diff_x)));
		stock->y1 = round(env->height / 2 + (env->height / 4) * env->diff_y);
	}
}

void	ft_win_form2_d1(t_env *env, t_stock  *stock, double win_form)
{
	if (win_form == 2.1)
	{
//		stock->x1 = env->width - env->width / 4;
//		stock->y1 = env->height / 2;
	}
	if (win_form == 2.2)
	{
		stock->x0 = round(stock->old_x0 + (env->width / 2 - stock->old_x1) * env->diff_x);
		stock->y0 = round(stock->old_y0 + (env->len_max / 2 - stock->old_y0) * env->diff_y);
		stock->x1 = round(stock->old_x1 - (env->width / 2 - stock->old_x1) * env->diff_x);
		stock->y1 = round(stock->old_y1 - (env->len_max / 2 - stock->old_y0) * env->diff_y);
		stock->old_x0 = stock->x0;
		stock->old_y0 = stock->y0;
		stock->old_x1 = stock->x1;
		stock->old_y1 = stock->y1;
	}
	if (win_form == 2.3)
	{
//		stock->x0 = ;
//		stock->y0 = ;
//		stock->x1 = ;
//		stock->y1 = ;
		stock->old_x0 = stock->x0;
		stock->old_y0 = stock->y0;
		stock->old_x1 = stock->x1;
		stock->old_y1 = stock->y1;
	}
	env->error = 0;
}

void	ft_win_form3_d1(t_env *env, t_stock  *stock, double win_form)
{
	if (win_form == 3.1)
	{
//		stock->x1 = env->width;
//		stock->y1 = env->height / 2;
	}
	if (win_form == 3.2)
	{
		stock->x0 = round(env->width / 2 + (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round(env->width - ((env->width / 4 * 1.2) - env->width / 4 * 1.2 * env->diff_x));
		stock->y1 = round(env->height / 2 + (env->height / 4) * env->diff_y);
	}
	if (win_form == 3.3)
	{
		stock->x0 = round(env->width / 2 - (env->width / 2 * env->diff_x));
		stock->y0 = round((env->height / 4 * 1.2) + (env->height / 4 * 0.8) * env->diff_y / (env->width / env->height));
		stock->x1 = round(env->width - (env->width / 2 * env->diff_x));
		stock->y1 = round(env->height / 2 + ((env->height / 4 * 0.8) * env->diff_y * (env->width / env->height)));
	}
}
