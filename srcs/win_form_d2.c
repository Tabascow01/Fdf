/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_form_d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:15:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/14 16:42:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_form1_d2(t_env *env, t_stock *stock, double win_form)
{
	if (win_form == 1.1)
	{
		stock->x1 = env->width / 8 * 0.8;
		stock->y1 = env->height / 2;
	}
	if (win_form == 1.2)
	{
		stock->x0 = round(env->width / 2 + (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round(env->width / 2 + ((env->width / 4 * 1.2) - (env->width / 4 * 1.2 * env->diff_x)));
		stock->y1 = round(env->height / 2 - (env->height / 4) * env->diff_y);
	}
	if (win_form == 1.3)
	{
		stock->x0 = round(env->width / 2 - (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round(env->width / 2 - ((env->width / 4 * 1.2) - env->width / 4 * 1.2 * env->diff_x));
		stock->y1 = round(env->height / 2 - (env->height / 4) * env->diff_y);
	}
}

void	ft_win_form2_d2(t_env *env, t_stock *stock, double win_form)
{
	if (win_form == 2.1)
	{
//		stock->x1 = env->width / 4;
//		stock->y1 = env->height / 2;
	}
	if (win_form == 2.2)
	{
//		stock->x0 = round();
//		stock->y0 = round();
//		stock->x1 = round();
//		stock->y1 = round();
//		stock->old_x0 = stock->x0;
//		stock->old_y0 = stock->y0;
//		stock->old_x1 = stock->x1;
//		stock->old_y1 = stock->y1;
	}
	if (win_form == 2.3)
	{
//		stock->x0 = round(stock->ori_x - ((stock->ori_x - stock->old_x1) * env->diff_x));
//		stock->y0 = round(stock->ori_y - ((stock->ori_y - stock->old_y0) * env->diff_y));
//		stock->x1 = round(stock->ori_x - ((stock->ori_x - stock->old_x1) * (1 - env->diff_x)));
//		stock->y1 = round(stock->ori_y - ((stock->ori_y - stock->old_y1) * (1 - env->diff_y)));
//		stock->old_x0 = stock->x0;
//		stock->old_y0 = stock->y0;
//		stock->old_x1 = stock->x1;
//		stock->old_y1 = stock->y1;
	}
	stock->ori_x = 0;
	env->error = 0;
}

void	ft_win_form3_d2(t_env *env, t_stock *stock, double win_form)
{
	if (win_form == 3.1)
	{
//		stock->x1 = 0;
//		stock->y1 = env->height / 2;
	}
	if (win_form == 3.2)
	{
		stock->x0 = round(env->width / 2 + (env->width / 4 * 1.2) * env->diff_x);
		stock->y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		stock->x1 = round((env->width / 4 * 1.2) - (env->width / 4 * 1.2 * env->diff_x));
		stock->y1 = round(env->height / 2 - (env->height / 4) * env->diff_y);
	}
	if (win_form == 3.3)
	{
		stock->x0 = round(env->width / 2 - (env->width / 2 * env->diff_x));
		stock->y0 = round(((env->height / 4 * 1.2) + ((env->height / 4 * 0.8) * env->diff_y / (env->width / env->height))));
		stock->x1 = round(0 + (env->width / 2 * env->diff_x));
		stock->y1 = round(env->height / 2 - ((env->height / 4 * 0.8) * env->diff_y * (env->width / env->height)));
	}
}
