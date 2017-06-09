/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 00:57:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/09 05:00:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_altitude(t_env *env, int *i)
{
	int		k;
	int		j;
	char	*altitude;

	j = 0;
	k = (*i);
	while (env->parser[k] && env->parser[k] != ' '
			&& env->parser[k] != ',' && env->parser[k] != '\n'
			&& ft_isdigit(env->parser[k]))
	{
		k++;
		j++;
	}
	if(!(altitude = ft_strnew(j)))
		return (0);
	ft_bzero(altitude, j);
	k = 0;
	while(env->parser[(*i)] && env->parser[(*i)] != ' '
			&& env->parser[(*i)] != ',' && env->parser[(*i)] != '\n'
			&& ft_isdigit(env->parser[(*i)]))
	{
		altitude[k++] = env->parser[(*i)];
		(*i) += 1;
	}
	altitude[k] = '\0';
	return (altitude);
}

char	**ft_store_altitude(t_env *env, t_parse *parser)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**tab;

	j = 0;
	if (env->size_y == 0 && env->size_x == 0)
		return (0);
	if (!(tab = (char **)malloc((env->size_y * env->size_x) * sizeof(tab) + 1)))
		return (0);
	if (!(parser->color =
			(char **)malloc((env->size_y * env->size_x)
				* sizeof(parser->color) + 1)))
		return (0);
	i = 0;
	k = 0;
	while (env->parser[i])
	{
		if (ft_isdigit(env->parser[i]) && (i == 0 || env->parser[i - 1] == ' '
				|| env->parser[i - 1] == '\n'))
		{
			count = 0;
			tab[j] = ft_altitude(env, &i);
			if (env->parser[i] == ',')
			{
				parser->color[k] = ft_store_color(env, &i);
				k++;
				count++;
			}
			if (count == 0)
			{
				parser->color[k] = ft_strnew(6);
				parser->color[k] = "(null)";
				k++;
			}
			j++;
		}
		i++;
	}
//	tab[j] = 0; // Error alloc
//	parser->color[k] = 0; // Error alloc
	return (tab);
}

char	*ft_store_color(t_env *env, int *i)
{
	int		k;
	int		j;
	char	*color;

	if (env->parser[(*i)] == ',' && env->parser[(*i) + 1] != '\0')
		(*i) += 1;
	k = (*i);
	j = 0;
	while (env->parser[k] && env->parser[k] != ' ')
	{
		k++;
		j++;
	}
	if (!(color = ft_strnew(j)))
		return (0);
	ft_bzero(color, j);
	j = (*i);
	k = 0;
	while (env->parser[j] && env->parser[j] != ' ')
	{
		color[k] = env->parser[j];
		k++;
		j++;
	}
	color[k] = '\0';
	(*i) += k;
	return (color);
}
