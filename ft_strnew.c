/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:42:48 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/13 18:44:35 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
