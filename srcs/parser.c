/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/20 01:48:27 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_counter_y(t_env *env)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (env->parser[i])
	{
		if (env->parser[i] == '\n')
			y++;
		i++;
	}
	env->size_y = y;
	return (0);
}

static	void	ft_store_map(t_parse *parser, t_env *env)
{
	int i;

	i = 0;
	env->parser = ft_get_file(parser->fd);
	ft_counter_y(env);
	parser->altitude = ft_store_altitude(env, parser);
	ft_printf("x[%d]\ny[%d]\n",env->size_x, env->size_y);
	ft_printf("color[\n%s]\n", parser->color[0]);
	ft_printf("altitude[\n%s]\n", parser->altitude[0]);
	ft_printf("parser:\n%s\n", env->parser);
}

static	void	ft_open_file(t_parse *parser, char **argv)
{
	parser->fd = open(argv[1],O_RDONLY);
}

int				ft_parser(t_parse *parser, t_env *lst, char **argv)
{
	parser = ft_init_parser();
	ft_open_file(parser, argv);
	ft_store_map(parser, lst);
//	ft_clear_parser(parser);
	return (0);
}
