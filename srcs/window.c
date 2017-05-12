#include "fdf.h"

void	ft_window(t_map *lst)
{
	ft_printf("[1]\n");
	lst->mlx_ptr = mlx_init();
	ft_printf("[2]\n");
	lst->mlx_win = mlx_new_window(lst->mlx_ptr, 750, 750, "Fdf");
	ft_printf("[3]\n");
	if (lst->mlx_win == NULL)
	{
		ft_putstr_fd("Error[", 2);
		ft_putnbr_fd(lst->error, 2);
		ft_putstr_fd("] opening window\n", 2);
	}
	//ft_display(lst);
	// Nothing after this point
	ft_event(lst);
	ft_printf("[4]\n");
	mlx_loop(lst->mlx_ptr);
}
