/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 00:57:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/21 23:00:46 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_altitude(t_env *env, int *i)
{
	int		k;
	char	*altitude;

	k = (*i);
	while (env->parser[k] && env->parser[k] != ' '
			&& env->parser[k] != ',')
		k++;
	if(!(altitude = ft_strnew(k)))
		return (0);
	ft_bzero(altitude, k);
	k = 0;
	while(env->parser[(*i)] && env->parser[(*i)] != ' '
			&& env->parser[(*i)] != ',')
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
	if (!(tab = (char **)malloc((env->size_y * env->size_x) * sizeof(tab))))
		return (0);
	if (!(parser->color =
			(char **)malloc((env->size_y * env->size_x)
				* sizeof(parser->color))))
		return (0);
	i = 0;
	k = 0;
	while (env->parser[i])
	{
		count = 0;
		if (env->parser[i] == '0' && env->parser[i + 1] == 'x')
		{
			parser->color[k++] = ft_store_color(env, &i);
			count++;
		}
		if (ft_isdigit(env->parser[i]) && env->parser[i - 1] == ' ')
		{
			if (count == 0)
				parser->color[k++] = "(null)";
			tab[j++] = ft_altitude(env, &i);
		}
		i++;
	}
	tab[j] = NULL;
	parser->color[k] = NULL;
	return (tab);
}

char	*ft_store_color(t_env *env, int *i)
{
	int		k;
	int		j;
	char	*color;

	k = (*i);
	j = k;
	while (env->parser[k] && env->parser[k] != ' ')
		k++;
	if (!(color = ft_strnew(k)))
		return (0);
	k = 0;
	while (env->parser[j] && env->parser[j] != ' ')
		color[k++] = env->parser[j++];
	color[k] = '\0';
	(*i) += k;
	return (color);
}
