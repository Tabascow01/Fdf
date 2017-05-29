/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 22:00:04 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/29 00:40:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_counter_y(t_env *env)
{
	int i;
	double counter;

	i = 0;
	counter = 0.0;
	env->size_y = 0.0;
	while (env->parser[i])
	{
		if (env->parser[i] == '\n')
			counter += 1;
		i++;
	}
	env->size_y = counter;
	return (0);
}

int		ft_counter_x(t_env *env)
{
	int i;
	double counter;
	int		color;

	counter	 = 0.0;
	i = 0;
	env->size_x = 0.0;
	while (env->parser[i] && env->parser[i] != '\n')
	{
		color = 0;
		if (env->parser[i] == '0' && env->parser[i + 1] == 'x')
		{
			i += 7;
			color++;
		}
		else if (env->parser[i] == ' ' || env->parser[i] == ',')
			i++;
		if ((env->parser[i - 1] == ' ' || env->parser[i - 1] == '\0'
					|| env->parser[i - 1] == '\n')
				&& ft_isdigit(env->parser[i]) && color == 0)
		{
			counter += 1.0;
			while(ft_isdigit(env->parser[i]) && env->parser[i]
					&& env->parser[i] != '\n')
				i++;
		}
	}
	env->size_x = counter;
	return (0);
}
