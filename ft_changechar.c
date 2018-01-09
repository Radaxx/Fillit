/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:21:07 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/22 10:27:45 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_changechar(char **str, int nb_line)
{
	int		i;
	int		j;
	char	carac;

	i = 0;
	j = 0;
	carac = 'A';
	while (i < nb_line)
	{
		if (str[i][0] == '\n')
		{
			i++;
			carac++;
		}
		while (str[i][j] != '\n')
		{
			if (str[i][j] == '#')
				str[i][j] = carac;
			j++;
		}
		j = 0;
		i++;
	}
	return (str);
}
