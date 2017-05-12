#include "fdf.h"

char	*ft_get_file(int fd)
{
	char	*str;
	int		size;
	int		sizeread;

	sizeread = 0;
	size = 0;
	if(!(str = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((sizeread = read(fd, str + size, BUFF_SIZE)) > 0)
	{
		if (sizeread == -1)
			return (0);
		size += sizeread;
		str = ft_reallocf(str, sizeread);
	}
	if (sizeread > 0)
	{
		size += sizeread;
		str = ft_reallocf(str, sizeread);
	}
	str[size] = '\0';
	return (str);
}
