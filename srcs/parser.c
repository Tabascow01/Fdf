/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/21 23:04:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_store_map(t_parse *parser, t_env *env)
{
	int i;

	i = 0;
	env->parser = ft_get_file(parser->fd);
	ft_counter_y(env);
	ft_counter_x(env);
	parser->altitude = ft_store_altitude(env, parser);

	ft_printf("parser:\n%s\n", env->parser);
	ft_printf("x[%d]\ny[%d]\n",env->size_x, env->size_y);
	ft_printf("color[\n%s]\n", parser->color[19]);
	ft_printf("altitude[\n%s]\n", parser->altitude[19]);
	ft_strdel(&env->parser);
//	ft_strdel(parser->color);
	ft_strdel(parser->altitude);
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
