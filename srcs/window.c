#include "fdf.h"

void	ft_window(t_map *lst)
{
	lst->mlx_ptr = mlx_init();
	lst->mlx_win = mlx_new_window(lst->mlx_ptr, 1080, 720, "Fdf");
	if (lst->mlx_win == NULL)
	{
		ft_putstr_fd("Error[", 2);
		ft_putnbr_fd(lst->error, 2);
		ft_putstr_fd("] opening window\n", 2);
	}

	// Nothing after this point
	ft_event(lst);
	mlx_loop(lst->mlx_ptr);
}
