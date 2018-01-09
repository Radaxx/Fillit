/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:28:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/08 15:49:09 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_callfunction(char *buffer)
{
	char	**str;
	char	**res;
	t_list	*lst;
	t_list	*tmp;
	int		nb_tetris;

	lst = NULL;
	str = ft_dimcor(buffer);
	ft_check(str, ft_nbline(buffer));
	str = ft_changechar(str, ft_nbline(buffer));
	nb_tetris = ft_nbtetris(buffer);
	while (nb_tetris)
	{
		ft_lstaddend(&lst, ft_lstnew(lst));
		nb_tetris--;
	}
	ft_coord(str, &lst, ft_nbline(buffer));
	ft_lststock(str, lst);
	res = ft_mapgen(lst);
	tmp = lst;
	ft_putnbr(ft_needrealloc(res, lst, tmp));
	return (str);
}

void		ft_read(char *av)
{
	char	**res;
	char	buffer[BUFF_SIZE];
	int		fd;
	int		ret;

	if (!(fd = open(av, O_RDONLY)))
		ft_error("error\n", 1);
	if (!(ret = read(fd, buffer, BUFF_SIZE)))
		ft_error("error\n", 1);
	buffer[ret] = '\0';
	if (buffer[0] != '.' && buffer[0] != '#')
		ft_error("error\n", 1);
	res = ft_callfunction(buffer);
	close(fd);
}

int			main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr("usage: ./fillit <source_file>\n");
		return (0);
	}
	ft_read(av[1]);
	return (0);
}
