/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:59:07 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/05 12:05:11 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_env		env;

	if (argc < 2 && argv)
		ft_error_usage();
	if (argv[2] != NULL && !ft_strcmp(argv[2], "-h"))
		ft_error_list();
	env = ft_init_env();
	env.error = ft_parser(&env, argv);
	if (env.error > 2)
		return (0);
	ft_window(&env);
//	ft_clear_env(&env); // Error ft_strdel();
	mlx_loop(env.mlx);
	return (0);
}
