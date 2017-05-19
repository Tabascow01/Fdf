/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/19 05:08:34 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_size_map(t_env *env)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	x = 0;
	while (env->parser[i])
	{
		if (env->parser[i] == '\n')
			y++;
		i++;
	}
	i = 0;
	while (env->parser[i] != '\n')
	{
		if ((ft_atoi(&env->parser[i]) != 0) || env->parser[i] != ' ')
			x++;
		i++;
	}
	env->size_y = y;
	env->size_x = x;
	ft_printf("x[%d]\ny[%d]\n",x ,y);
	return (0);
}

static	void	ft_store_map(t_parse *parser, t_env *env)
{
	env->parser = ft_get_file(parser->fd);
	ft_size_map(env);
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
	ft_clear_parser(parser);
	return (0);
}
