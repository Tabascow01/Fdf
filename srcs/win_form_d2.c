/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_form_d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:15:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/08 04:33:49 by mchemakh         ###   ########.fr       */
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
		len->o_x1 = env->width / 4 * 0.8;
		len->o_y1 = env->height / 2;
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
}

void	ft_o_coord(t_len *len, t_stock *stock)
{
	stock->y1 = len->o_y1;
	stock->x1 = len->o_x1;
}
