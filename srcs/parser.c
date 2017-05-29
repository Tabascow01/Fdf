/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/29 00:38:21 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_store_map(t_parse *parser, t_env *env)
{
	env->parser = ft_get_file(parser->fd);
	parser->altitude = ft_store_altitude(env, parser);
	ft_printf("%s\n", env->parser);
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
	return (0);
}
