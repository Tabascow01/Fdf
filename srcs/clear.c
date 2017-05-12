#include "fdf.h"

void	ft_clear_lst(t_map *lst)
{
	ft_strdel(&lst->map_str);
	lst->map_int = NULL;
	lst->error = 0;
	lst->mlx_ptr = NULL;
	lst->mlx_win = NULL;
	free(lst);
}

void	ft_clear_lst_rd(t_read *lst)
{
	lst->fd = 0;
	free(lst);
}
