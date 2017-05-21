/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 22:00:04 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/21 22:01:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_counter_y(t_env *env)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (env->parser[i])
	{
		if (env->parser[i] == '\n')
			counter++;
		i++;
	}
	env->size_y = counter;
	return (counter);
}

int		ft_counter_x(t_env *env)
{
	int i;
	int counter;

	counter	 = 0;
	i = 0;
	while (env->parser[i] != '\n')
	{
		if (env->parser[i] == '0' && env->parser[i + 1] == 'x')
			i += 7;
		if (env->parser[i] == ' ' || env->parser[i] == ',')
			i++;
		if (env->parser[i] != ' ' && env->parser[i] != ' '
				&& ft_isdigit(env->parser[i]))
			counter++;
		i++;
	}
	env->size_x = counter;
	return (counter);
}
