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

static char		*ft_altitude(t_env *env, int *i)
{
	int		k;
	char	*altitude;

	k = (*i);
	while (ft_isdigit(env->parser[k]) && env->parser[k])
		k++;
	if(!(altitude = ft_strnew(k)))
		return (0);
	k = 0;
	while(env->parser[(*i)] && env->parser[(*i)] != ' ' && env->parser[(*i)] != ',')
	{
		altitude[k++] = env->parser[(*i)];
		(*i) += 1;
	}
	altitude[k] = '\0';
	return (0);
}

char	**ft_store_altitude(t_env *env, t_parse *parser)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	ft_counter_x(env);
	if (!(tab = (char **)malloc(env->size_x * env->size_y * sizeof(tab))))
		return (0);
	if (!(parser->color =
			(char **)malloc((env->size_x * env->size_y)
				* sizeof(parser->color))))
		return (0);
	i = 0;
	k = 0;
	while (env->parser[i])
	{
		if (env->parser[i] == ' ' || env->parser[i] == ',')
			i++;
		else if (env->parser[i] == '0' && env->parser[i + 1] == 'x')
			parser->color[k++] = ft_store_color(env, &i);
		else if (ft_isdigit(env->parser[i]))
			tab[j++] = ft_altitude(env, &i);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	*ft_store_color(t_env *env, int *i)
{
	int		k;
	char	*color;

	k = (*i);
	while (ft_isdigit(env->parser[k]) && env->parser[k]
			&& env->parser[k] == 'x')
		k++;
	if (!(color = ft_strnew(k)))
		return (0);
	k = 0;
	while (env->parser[(*i)] && ft_isdigit(env->parser[(*i)])
			&& env->parser[(*i)] != ' ' && env->parser[(*i)] == 'x')
	{
		color[k++] = env->parser[(*i)];
		i += 1;
	}
	color[k] = '\0';
	return (color);
}

