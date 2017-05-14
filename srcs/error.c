/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:29:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/14 02:39:55 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_win_ptr(t_map *lst)
{
	lst->error = 2;
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(lst->error, 2);
	ft_putstr_fd("] window opening\n", 2);
	exit(-1);
}

void	ft_error_mlx_ptr(t_map *lst)
{
	lst->error = 1;
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(lst->error, 2);
	ft_putstr_fd("] mlx initialisation\n", 2);
	exit(-1);
}
