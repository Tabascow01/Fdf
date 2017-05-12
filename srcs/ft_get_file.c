#include "fdf.h"

char	*ft_get_file(int fd)
{
	char	*str;
	int		size;
	int		sizeread;
	int		buff_size;

	sizeread = 0;
	size = 0;
	buff_size = 1024;
	str = ft_strnew(buff_size);
	while ((sizeread = read(fd, str + size, buff_size)) > 0)
	{
		size += sizeread;
		str = ft_reallocf(str, sizeread);
	}
	return (str);
}
