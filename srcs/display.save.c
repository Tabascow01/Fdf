#include "fdf.h"

void	ft_display(t_map *lst)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int x;
	int y;
	int dx;
	int dy;
	int incrE;
	int incrNE;
	int e;
	int incX;
	int incY;

	y0 = 250;
	x0 = 250;
	x1 = 750;
	y1 = 750;
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	incrE = 2 * dy;
	incrNE = 2 * (dy - dx);
	e = 2 * dy - dx;

	if (dx > 0)
		incX = 1;
	else
	{
		incX = -1;
		dx = -dx;
	}
	if (dy > 0)
		incY = 1;
	else
	{
		incY = -1;
		dy = -dy;
	}
	if (dx > dy)
	{
		while (x <= x1)
		{
			mlx_pixel_put(lst->mlx_ptr, lst->mlx_win, x, y,0xFFFFFF);
			x++;
		}
		if (e >= 0)
		{
			y += 1;
			e += incrE;
		}
		else
			e += incrNE;
	}
	else
	{
		while (y <= y1)
		{
			mlx_pixel_put(lst->mlx_ptr, lst->mlx_win, y, x,0xFFFFFF);
			y++;
		}
		if (e >= 0)
		{
			y += 1;
			e += incrE;
		}
		else
			e += incrNE;
	}
	return ;
}
