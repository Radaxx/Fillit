/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:51:58 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/13 19:04:19 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(char *str, int fd)
{
	ft_putstr(str);
	exit(fd);
}

int		ft_check(char **str)
{
	ft_check_size(str);
	ft_check_char(str);
	ft_check_tetris_number(str);
	ft_check_tetris_total(str);
	return (0);
}

int		ft_check_size(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		ft_putchar('A');
		while (str[i][j] != '\n')
			j++;
		if (j != 4)
			ft_error("Usage: Wrong shape !\n", 1);
		j = 0;
		i++;
		if (str[i][0] == '\n')
			i++;
	}
	return (0);
}

int		ft_check_char(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j] != '\n')
		{
			if (str[i][j] != '.' || str[i][j] != '#' || str[i][j] != '\n')
				ft_error("Usage: Wrong character, set the tetriminos using '#'\n", 1);
			j++;
		}
		j = 0;
		i++;
		if (str[i][0] == '\n')
			i++;
	}
	return (0);
}

int		ft_check_tetris_number(char **str)
{
	int		i;
	int		j;
	int		nb_tetris;

	i = 0;
	j = 0;
	nb_tetris = 0;
	while (str[i])
	{
		while (str[i][j] != '\n')
		{
			if (str[i][j] == '#')
				nb_tetris++;
			j++;
		}
		j = 0;
		i++;
		if (str[i][0] == '\n')
		{
			if (nb_tetris < 4 || nb_tetris > 4)
				ft_error("Usage: Only 4 pieces is allowed for a tetriminos\n", 1);
			i++;
			nb_tetris = 0;
		}
	}
	return (0);
}

int		ft_check_tetris_total(char **str)
{
	int		i;
	int		j;
	int		nb_tetris_total;

	i = 0;
	j = 0;
	nb_tetris_total = 0;
	while (str[i])
	{
		while (str[i][j] != '\n')
		{
			if (str[i][j] == '#')
				nb_tetris_total++;
			j++;
		}
		j = 0;
		i++;
		if (str[i][0])
			i++;
	}
	if (nb_tetris_total > 104)
		ft_error("Usage: Too many tetriminos, 26 max !\n", 1);
	return (0);
}
