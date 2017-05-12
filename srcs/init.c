#include "fdf.h"

t_read	*ft_init_lst_rd(void)
{
	t_read	*list;

	list = (t_read *)malloc(sizeof(list));
	list->next = NULL;
	list->line = NULL;
	list->fd = 0;
	return(list);
}

t_map	*ft_init_lst(void)
{
	t_map	*list;

	list = (t_map *)malloc(sizeof(list));
	list->next = NULL;
	list->prev = NULL;
	list->first = list;
	list->map_str = NULL;
	list->map_int = NULL;
	list->error = 0;
	list->mlx_ptr = NULL;
	list->mlx_win = NULL;
	return (list);
}
