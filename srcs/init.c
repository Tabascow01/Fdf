/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/14 03:55:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_calc	ft_init_calcul(void)
{
	t_calc calc;

	calc.x0 = 250;
	calc.y0 = 250;
	calc.x1 = 750;
	calc.y1 = 750;
	calc.dx = calc.x1 - calc.x0;
	calc.dy = calc.y1 - calc.y0;
	return (calc);
}

t_parse	*ft_init_parser(void)
{
	t_parse	*parser;

	parser = (t_parse *)malloc(sizeof(parser));
	parser->next = NULL;
	parser->fd = 0;
	return(parser);
}

t_env	ft_init_env(void)
{
	t_env	env;

	env.parser = NULL;
	env.error = 0;
	env.height = 720;
	env.width = 1280;
	env.title = "Fdf";
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		ft_error_mlx_ptr(&env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, env.title);
	if (env.win == NULL)
		ft_error_win_ptr(&env);
	return (env);
}
