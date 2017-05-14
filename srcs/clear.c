/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:17 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/14 03:44:19 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_env(t_env *env)
{
	if (env->parser != NULL)
		ft_strdel(&env->parser);
	env->error = 0;
	env->mlx = NULL;
	env->win = NULL;
	if (env != NULL)
		free(env);
}

void	ft_clear_parser(t_parse *parser)
{
	parser->fd = 0;
	if (parser != NULL)
		free(parser);
}
