/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:20 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:06:58 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strmemalloc;

	strmemalloc = (char*)malloc(size + 1);
	if (strmemalloc != NULL)
	{
		ft_bzero(strmemalloc, size + 1);
		return (strmemalloc);
	}
	return (0);
}
