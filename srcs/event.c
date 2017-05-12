#include "fdf.h"

int		ft_key_hook_exit(int keycode, void *param)
{
	t_map *lst;

	lst = param;
	if (keycode == 53)
	{
		ft_clear_lst(lst);
		exit(1);
	}
	return (0);
}

int		ft_key_hook_print(int keycode, void *param)
{
	ft_printf("Keycode[%d]\n",keycode);
	ft_key_hook_exit(keycode, param);
	return (0);
}

void	ft_event(t_map *lst)
{
	mlx_key_hook(lst->mlx_win, ft_key_hook_exit, lst);
	mlx_key_hook(lst->mlx_win, ft_key_hook_print, lst);
}
