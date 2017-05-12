/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:59:07 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/11 05:12:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	int		err;
	t_map	*lst;
	t_read	*lst_rd;

	if (argc != 2)
		return (0);
	lst_rd = NULL;
	lst = ft_init_lst();
	err = ft_parser(lst_rd, lst, argv);

	ft_clear_lst(lst);
//	sleep(30);
	return (0);
}
