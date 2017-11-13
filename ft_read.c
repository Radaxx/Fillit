/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:05:15 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/13 18:53:36 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_read(char *av)
{
	char	**res;
	char	buffer[BUFF_SIZE];
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	ret = read(fd, buffer, BUFF_SIZE);
	buffer[ret] = '\0';
	res = ft_storage(buffer);
	close(fd);
}
