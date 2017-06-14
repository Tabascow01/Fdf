/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/14 16:49:13 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_len(t_env *env, t_stock *stock, double win_form, int d)
{
	if (d == 1)
	{
		ft_win_form1_d1(env, stock, win_form);
		ft_win_form2_d1(env, stock, win_form);
		ft_win_form3_d1(env, stock, win_form);
	}
	if (d == 2)
	{
		ft_win_form1_d2(env, stock, win_form);
		ft_win_form2_d2(env, stock, win_form);
		ft_win_form3_d2(env, stock, win_form);
	}
}

t_stock	ft_init_stock(double x0, double x1, double y0, double y1)
{
	t_stock stock;

	stock.x0 = x0;
	stock.x1 = x1;
	stock.y0 = y0;
	stock.y1 = y1;
	return (stock);
}

t_calc		ft_init_calcul(t_stock stock)
{
	t_calc calc;

	calc.x0 = stock.x0;
	calc.y0 = stock.y0;
	calc.x1 = stock.x1;
	calc.y1 = stock.y1;
	calc.dx = calc.x1 - calc.x0;
	calc.dy = calc.y1 - calc.y0;
	calc.a = 0.0;
	calc.b = 0.0;
	calc.color = 0x00FF00;
	return (calc);
}

t_parse		*ft_init_parser(void)
{
	t_parse	*parser;
	parser = (t_parse *)malloc(sizeof(t_parse));
	parser->next = NULL;
	parser->fd = 0;
	parser->color = NULL;
	parser->altitude = NULL;
	return(parser);
}

t_env		ft_init_env(void)
{
	t_env	env;

	env.diff = 0.0;
	env.diff_x = 0.0;
	env.diff_y = 0.0;
	env.adj_y = 0.0;
	env.adj_x = 0.0;
	env.parser = NULL;
	env.size_y = 0.0;
	env.size_x = 0.0;
	env.len_max = 0.0;
	env.error = 0;
	env.height = 1000;
	env.width = 1500;
	env.title = "Fdf";
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		ft_error_mlx_ptr(&env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, env.title);
	if (env.win == NULL)
		ft_error_win_ptr(&env);
	return (env);
}
