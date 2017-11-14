/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:51:58 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/14 18:55:12 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(char *str, int fd)
{
	ft_putstr(str);
	exit(fd);
}

int		ft_check(char **str, int nb_line)
{
	ft_check_size(str, nb_line);
	ft_putstr("CHECK SIZE PASS\n");
	ft_check_char(str, nb_line);
	ft_putstr("CHECK CHAR PASS \n");
	ft_check_tetris_number(str, nb_line);
	ft_putstr("CHECK TETRIS PASS \n");
	return (0);
}

int		ft_check_size(char **str, int nb_line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_line)
	{
		j = 0;
		while (str[i][j] != '\n')
			j++;
		if (j != 4)
			ft_error("Error: Wrong shape !\n", 1);
		i++;
		if (i < nb_line && str[i][0] == '\n')
			i++;
	}
	return (0);
}

int		ft_check_char(char **str, int nb_line)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (str[i][j] != '\n')
		{
			if (str[i][j] != '.' && str[i][j] != '#')
				ft_error("Error: Wrong caracter\n", 1);
			j++;
		}
		i++;
		if (i < nb_line && str[i][0] == '\n')
			i++;
	}
	return (0);
}

int		ft_check_tetris_number(char **str, int nb_line)
{
	int		i;
	int		j;
	int		nb_tetris;

	i = 0;
	nb_tetris = 0;
	while (i < nb_line)
	{
		j = 0;
		while (str[i][j] != '\n')
		{
			if (str[i][j] == '#')
				nb_tetris++;
			j++;
		}
		i++;
		if (i < nb_line && str[i][0] == '\n')
		{
			nb_tetris = 0;
			i++;
		}
	}
	return (0);
}
