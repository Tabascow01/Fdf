/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 03:44:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/21 22:49:15 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_bzero(str, BUFF_SIZE);
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
