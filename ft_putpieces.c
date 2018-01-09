/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:05 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/28 17:25:35 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_needrealloc(char **res, t_list *lst, t_list *tmp)
{
	while ((ft_solver(res, lst, 0)) == 0)
	{
		res = ft_maprealloc(res);
		ft_solver(res, tmp, 0);
	}
	return (0);
}

int		ft_solver(char **res, t_list *lst, int pos)
{
	int i;
	int j;

	i = pos / ft_strlen(res[0]);
	j = pos % ft_strlen(res[0]);
	if ((ft_findspaces(i, j, res, lst)) == 1)
	{
		ft_checkend(lst, res);
		if ((ft_solver(res, lst->next, 0)) == 0)
		{
			ft_dellasttetris(res, lst);
			ft_solver(res, lst, pos + 1);
		}
	}
	else
	{
		if (i < ft_strlen(res[0]) && j < ft_strlen(res[0]))
			ft_solver(res, lst, pos + 1);
		else
			return (0);
	}
	return (0);
}

int		ft_findspaces(int i, int j, char **res, t_list *lst)
{
	int	k;
	int	l;
	int len;

	k = 0;
	l = 0;
	len = ft_strlen(res[0]);
	while (k < (lst->ymax - lst->ymin) + 1)
	{
		while (lst->piece[k][l])
		{
			if (lst->piece[k][l] != '.')
			{
				if (i + k >= len || j + l >= len)
					return (0);
				if (res[i + k][j + l] != '.')
					return (0);
			}
			l++;
		}
		l = 0;
		k++;
	}
	res = ft_putpiece(res, lst, i, j);
	return (1);
}

char	**ft_putpiece(char **res, t_list *lst, int i, int j)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < (lst->ymax - lst->ymin) + 1)
	{
		while (lst->piece[k][l])
		{
			if (lst->piece[k][l] != '.')
			{
				res[i + k][j + l] = lst->piece[k][l];
			}
			l++;
		}
		l = 0;
		k++;
	}
	return (res);
}

char	**ft_dellasttetris(char **res, t_list *lst)
{
	int	k;
	int	l;
	int i;
	int j;
	int len;

	k = 0;
	l = 0;
	i = 0;
	j = 0;
	len = ft_strlen(res[0]);
	while (lst->piece[k][l] == '.')
		l++;
	while (i < len)
	{
		while (res[i][j])
		{
			if (res[i][j] == lst->piece[k][l])
				res[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}
