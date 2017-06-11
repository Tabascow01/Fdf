/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_form_d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:15:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/09 04:25:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_form1_d2(t_env *env, t_len *len, double win_form)
{
	if (win_form == 1.1)
	{
		len->o_x1 = env->width / 8 * 0.8;
		len->o_y1 = env->height / 2;
	}
	if (win_form == 1.2)
	{
		len->o_x1 = env->width / 8 * 0.8;
		len->o_y1 = env->height / 2;
	}
	if (win_form == 1.3)
	{
		len->o_x1 = env->width / 8 * 0.8;
		len->o_y1 = env->height / 2;
	}
}

void	ft_win_form2_d2(t_env *env, t_len *len, double win_form)
{
	if (win_form == 2.1)
	{
		len->o_x1 = env->width / 4 * 0.8;
		len->o_y1 = env->height / 2;
	}
	if (win_form == 2.2)
	{
		len->o_x0 = round(env->width / 2 - (env->width / 4 * 1.2) * env->diff_x);
		len->o_y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);
		len->o_x1 = round(env->width / 2 + ((env->width / 4 * 1.2) - (env->width / 4 * 1.2 * env->diff_x)));
		len->o_y1 = round(env->height / 2 + (env->height / 4) * env->diff_y);
	}
	if (win_form == 2.3)
	{
		len->o_x0 = round(env->width / 2 - (env->width / 4 * 1.2) * env->diff_x);
		len->o_y0 = round(env->height / 4 + (env->height / 4) * env->diff_y);

		len->o_x1 = round(env->width / 2 - ((env->width / 4 * 1.2) - env->width / 4 * 1.2 * env->diff_x));
		len->o_y1 = round(env->height / 2 - (env->height / 4) * env->diff_y);
	}
}

void	ft_win_form3_d2(t_env *env, t_len *len, double win_form)
{
	if (win_form == 3.1)
	{
		len->o_x1 = 0;
		len->o_y1 = env->height / 2;
	}
	if (win_form == 3.2)
	{
		len->o_x1 = env->width / 8 * 0.8;
		len->o_y1 = env->height / 2;
	}
	if (win_form == 3.3)
	{
		len->o_x1 = env->width / 8 * 0.8;
		len->o_y1 = env->height / 2;
	}
}

void	ft_o_coord(t_len *len, t_stock *stock)
{
	if (len->o_x0 > 0)
		stock->x0 = len->o_x0;
	if (len->o_y0 > 0)
		stock->y0 = len->o_y0;
	stock->y1 = len->o_y1;
	stock->x1 = len->o_x1;
}
