/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:33 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/29 01:00:05 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_hook_print(int keycode, void *param)
{
	t_env *env;

	env = param;
	ft_printf("Keycode[%d]\n",keycode);
	return (0);
}

int		ft_key_hook_exit(int keycode, void *param)
{
	t_env *env;

	env = param;
	ft_key_hook_print(keycode, param);
	if (keycode == 53)
		exit(1);
	return (0);
}

int		ft_key_hook_event(int keycode, void *param)
{
	t_env *env;

	env = param;
	if (keycode == 53)
		ft_key_hook_exit(keycode, param);
	else if (keycode == 37)
		ft_test_leaks();
	else
		ft_key_hook_print(keycode, param);
	return (0);
}

int		ft_event(t_env *env)
{
	mlx_key_hook(env->win, ft_key_hook_event, env);
	return (0);
}
