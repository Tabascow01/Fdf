/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:59:07 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/20 01:34:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_env		env;
	t_parse		*parser;

	if (argc != 2)
		return (0);
	parser = NULL;
	env = ft_init_env();
	env.error = ft_parser(parser, &env, argv);
	if (env.error != 0)
		ft_putstr_fd("Error[1] parser\n", 2);
//	ft_window(&env);
//	mlx_loop(env.mlx);
	return (0);
}
