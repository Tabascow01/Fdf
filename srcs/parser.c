#include "fdf.h"

static	void	ft_store_map(t_read *lst_rd, t_map *lst)
{
	lst->map_str = ft_get_file(lst_rd->fd);
}

static	void	ft_open_file(t_read	*lst_rd, char **argv)
{
	lst_rd->fd = open(argv[1],O_RDONLY);
}

int				ft_parser(t_read *lst_rd, t_map *lst, char **argv)
{
	lst_rd = ft_init_lst_rd();
	ft_open_file(lst_rd, argv);
	ft_store_map(lst_rd, lst);
//	ft_printf("Map:\n[\n%s]\n",lst->map_str);
//	ft_clear_lst_rd(lst_rd);
	return (0);
}
