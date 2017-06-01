/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:59:07 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/01 00:10:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_env		env;

	if (argc != 2 && argv)
		return (0);
	env = ft_init_env();
	env.error = ft_parser(&env, argv);
	if (env.error != 0)
		ft_putstr_fd("Error[1] parser\n", 2);
//	ft_window(&env);
//	ft_clear_env(&env); // Error ft_strdel();
//	mlx_loop(env.mlx);
	return (0);
}
