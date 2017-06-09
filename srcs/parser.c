/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/09 05:00:13 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_store_map(t_parse *parser, t_env *env)
{
	env->parser = ft_get_file(parser->fd);
	ft_counter_y(env);
	ft_counter_x(env); //Error with color
	parser->altitude = ft_store_altitude(env, parser);
//	printf("parser: %s\n", env->parser);
//	printf("[%s]\n",parser->color[1]);
}

static	void	ft_open_file(t_parse *parser, char **argv)
{
	parser->fd = open(argv[1],O_RDONLY);
}

int				ft_parser(t_env *lst, char **argv)
{
	t_parse *parser;

	parser = ft_init_parser();
	ft_open_file(parser, argv);
	ft_store_map(parser, lst);
//	ft_clear_parser(parser); // Error ft_strdel();
	return (0);
}
