/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:07:52 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/20 16:48:13 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lststock(char **str, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (lst)
	{
		if (!(lst->piece = (char **)malloc(sizeof(char *) *
						(lst->ymax - lst->ymin + 1) + 1)))
			lst->piece = NULL;
		while (i < (lst->ymax - lst->ymin) + 1)
		{
			lst->piece[i] = ft_strsub(str[lst->ymin + i], lst->xmin,
					(lst->xmax - lst->xmin) + 1);
			i++;
		}
		i = 0;
		lst = lst->next;
	}
	lst = tmp;
}

void	ft_putpieces(t_list *lst)
{
	int	i;

	i = 0;
	ft_putchar('\n');
	while (lst)
	{
		while (lst->piece[i])
		{
			ft_putstr(lst->piece[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		lst = lst->next;
	}
}
