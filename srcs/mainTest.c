/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:59:07 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/11 05:10:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook_exit(int keycode, void *param)
{
	param = NULL;
	ft_printf("keycode[%d]\n",keycode);
	if (keycode == 53)
		exit(-1);
	return (0);
}

int		main(int argc, char *argv[])
{
	argc = 0;
	argv = 0;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*param;
	int		x;
	int		y;


	param = NULL;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr,1000,1000,"Fdf");
	if (mlx_win == NULL)
		perror("Error opening new window\n");
/*
	y = 250;
	while (y < 750)
	{
		x = 250;
		while(x < 750)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFAAAA);
			x++;
		}
		y++;
	}
*/
	mlx_key_hook(mlx_win, key_hook_exit, param);

	// Nothing before this point
	mlx_loop(mlx_win);
	return (0);
}
