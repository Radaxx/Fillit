/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenfc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:04:52 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/22 11:41:00 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_genforx(char **res, int len)
{
	int	i;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (!(res[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		res[i][len + 1] = '\0';
		i++;
	}
	return (res);
}

char	**ft_genfory(char **res, int len)
{
	int	i;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (!(res[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		res[i][len + 1] = '\0';
		i++;
	}
	return (res);
}
