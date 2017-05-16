/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:23 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/14 03:59:41 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_display(t_env *env)
{
	t_calc	calc;

	calc = ft_init_calcul();
	ft_printf("env.error [%d]\n", env->error);
	return (0);
}
