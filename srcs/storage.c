/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 00:57:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/20 02:34:24 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_counter_x(t_env *env)
{
	int i;
	int counter;

	counter = 0;
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

void	ft_store_altitude(t_parse *parser, t_env *env)
{
	int i;
	int j;

	j = 0;
	i = ft_counter_x(env);
	ft_printf("y[%d]\nx[%d]\n", env->size_y, env->size_x);
	parser->altitude = ft_strnew(i);
	i = 0;
	while (env->parser[i])
	{
		if (env->parser[i] == ',')
			i++;
		if (env->parser[i] != ' ' && env->parser[i] != ','
				&& ft_isdigit(env->parser[i]))
		{
			while (env->parser[i] && env->parser[i] != ' '
						&& env->parser[i] != ',')
			parser->altitude[j++] = env->parser[i++];
		}
		if (env->parser[i] == '0' && env->parser[i + 1] == 'x')
			ft_store_color(parser, env, &i);
		i++;
	}
	parser->altitude[i] = 0;
}

void	ft_store_color(t_parse *parser, t_env *env, int *i)
{
	int			j;
	int			counter;
	char		**tmp;

	j = 0;
	tmp = parser->color;
	counter = ft_counter_x(env);
	if (parser->color == NULL)
		parser->color = (char **)malloc(sizeof(char *) * counter);
	while (env->parser[(*i)] != ' ' && env->parser[(*i)])
	{
		if (env->parser[(*i)] == '0' && env->parser[(*i - 1)] == 'x')
		{
			if (ft_ishex(&env->parser[(*i)]))
			{
				(*parser->color) = ft_strnew(6);
				(*parser->color)[j++] = env->parser[(*i)];
				parser->color++;
			}
		}
		(*i) += 1;
	}
}
