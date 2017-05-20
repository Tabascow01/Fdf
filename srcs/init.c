/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/20 00:47:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock	ft_init_stock(int x0, int x1, int y0, int y1)
{
	t_stock stock;

	stock.x0 = x0;
	stock.x1 = x1;
	stock.y0 = y0;
	stock.y1 = y1;
	return (stock);
}

t_calc	ft_init_calcul(t_stock stock)
{
	t_calc calc;

	calc.x0 = stock.x0;
	calc.y0 = stock.y0;
	calc.x1 = stock.x1;
	calc.y1 = stock.y1;
	calc.dx = calc.x1 - calc.x0;
	calc.dy = calc.y1 - calc.y0;
	calc.a = 0;
	calc.b = 0;
	calc.color = 0xFFFFFF;
	return (calc);
}

t_parse	*ft_init_parser(void)
{
	t_parse	*parser;

	parser = (t_parse *)malloc(sizeof(parser));
	parser->next = NULL;
	parser->fd = 0;
	parser->color = NULL;
	parser->altitude = 0;
	return(parser);
}

t_env	ft_init_env(void)
{
	t_env	env;

	env.parser = NULL;
	env.size_y = 0;
	env.size_x = 0;
	env.error = 0;
	env.height = 1080;
	env.width = 1920;
	env.title = "Fdf";
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		ft_error_mlx_ptr(&env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, env.title);
	if (env.win == NULL)
		ft_error_win_ptr(&env);
	return (env);
}
