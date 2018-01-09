/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:20:19 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/28 17:25:22 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(char *str, int fd)
{
	ft_putstr(str);
	exit(fd);
}

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(size + 1)))
		return (0);
	while (i <= size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	const char	*tmp_src;

	i = 0;
	tmp_src = src;
	while (tmp_src[i])
	{
		dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
