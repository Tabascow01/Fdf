/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:29:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/14 03:28:01 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_usage()
{
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("./fdf [filename] <option>\n", 2);
	ft_putstr_fd("Option:\n", 2);
	ft_putstr_fd("-h {Errors list}\n", 2);
	exit(-1);
}

void	ft_error_list()
{
	ft_putstr_fd("Error List:\n", 2);
	ft_putstr_fd("[0]->None\n", 2);
	ft_putstr_fd("[1]->init\n", 2);
	ft_putstr_fd("[2]->window\n", 2);
	ft_putstr_fd("[3]->parser/files\n", 2);
	ft_putstr_fd("[4]->N/A\n", 2);
	ft_putstr_fd("[5]->N/A\n", 2);
	ft_putstr_fd("[6]->N/A\n", 2);
	ft_putstr_fd("[7]->N/A\n", 2);
	ft_putstr_fd("[8]->N/A\n", 2);
	ft_putstr_fd("[9]->N/A\n", 2);
	exit(-1);
}

void	ft_error_parser(t_env *env)
{
	env->error = 3;
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(env->error, 2);
	ft_putstr_fd("] fichier vide\n" , 2);
}

void	ft_error_win_ptr(t_env *env)
{
	env->error = 2;
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(env->error, 2);
	ft_putstr_fd("] window opening\n", 2);
	exit(-1);
}

void	ft_error_mlx_ptr(t_env *env)
{
	env->error = 1;
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(env->error, 2);
	ft_putstr_fd("] mlx initialisation\n", 2);
	exit(-1);
}
