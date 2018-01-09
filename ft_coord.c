/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:22:56 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/22 15:01:28 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_setcoord(t_list **lst)
{
	(*lst)->ymax = 0;
	(*lst)->ymin = 128;
	(*lst)->xmax = 0;
	(*lst)->xmin = 5;
}

void		ft_changecoord(t_list **lst, char **str, int i, int j)
{
	while (str[i][j] != '\n')
	{
		if (str[i][j] != '.' && str[i][j] != '\n')
		{
			if ((*lst)->ymin >= i)
				(*lst)->ymin = i;
			if ((*lst)->ymax <= i)
				(*lst)->ymax = i;
			if ((*lst)->xmin >= j)
				(*lst)->xmin = j;
			if ((*lst)->xmax <= j)
				(*lst)->xmax = j;
		}
		j++;
	}
}

void		ft_coord(char **str, t_list **lst, int nb_lines)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = *lst;
	ft_setcoord(lst);
	while (i < nb_lines)
	{
		if (str[i][0] != '\n')
		{
			ft_changecoord(lst, str, i, j);
			i++;
			j = 0;
		}
		else
		{
			i++;
			*lst = (*lst)->next;
			ft_setcoord(lst);
		}
	}
	*lst = tmp;
}

void		ft_putcoord(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		ft_putnbr((*lst)->ymin);
		ft_putchar(' ');
		ft_putnbr((*lst)->ymax);
		ft_putchar(' ');
		ft_putnbr((*lst)->xmin);
		ft_putchar(' ');
		ft_putnbr((*lst)->xmax);
		ft_putchar('\n');
		*lst = (*lst)->next;
	}
	*lst = tmp;
}
