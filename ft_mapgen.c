/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:36:37 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/22 11:40:49 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_mapgen(t_list *lst)
{
	char	**res;
	int		i;
	int		len;

	i = 0;
	res = NULL;
	if ((lst->xmax - lst->xmin) > (lst->ymax - lst->ymin))
	{
		len = lst->xmax - lst->xmin + 1;
		res = ft_genforx(res, len);
	}
	else
	{
		len = lst->ymax - lst->ymin + 1;
		res = ft_genfory(res, len);
	}
	res = ft_emptymap(res, len);
	return (res);
}

char	**ft_emptymap(char **res, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			res[i][j] = '.';
			j++;
		}
		res[i][j] = '\0';
		j = 0;
		i++;
	}
	return (res);
}

void	ft_showmap(char **res)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(res[i]);
	while (i < len)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**ft_maprealloc(char **res)
{
	int		len;
	int		i;
	char	**tmp;

	i = 0;
	len = ft_strlen(res[i]);
	if (!(tmp = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (i < len + 1)
	{
		if (!(tmp[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i++;
	}
	tmp = ft_emptymap(tmp, len + 1);
	ft_freemap(res);
	return (tmp);
}

void	ft_freemap(char **res)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(res[0]);
	while (i < len)
	{
		free(res[i]);
		i++;
	}
}
