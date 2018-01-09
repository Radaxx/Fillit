/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:51:58 by ccharrie          #+#    #+#             */
/*   Updated: 2017/12/01 14:41:40 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_size(char **str, int nb_line)
{
	int		i;
	int		j;
	int		cpt;

	i = 0;
	cpt = 0;
	while (i < nb_line)
	{
		j = 0;
		while (str[i][j] != '\n')
			j++;
		if (str[i][0] != '\n' && j != 4)
			return (1);
		if (i < nb_line && str[i][0] == '\n')
		{
			i++;
			cpt = 0;
		}
		i++;
		cpt++;
	}
	if (cpt != 4)
		return (1);
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
				return (1);
			j++;
		}
		i++;
		if (i < nb_line && str[i][0] == '\n')
		{
			if (i + 1 < nb_line && str[i + 1][0] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

int		ft_check_tetris_number(char **str, int nb_line, t_var *var)
{
	while (var->i < nb_line)
	{
		var->j = 0;
		while (str[var->i][var->j] != '\n')
		{
			if (str[var->i][var->j] == '#')
			{
				var->nb_tetris++;
				var->lk = var->lk + ft_check_link(str, nb_line, var->i, var->j);
			}
			var->j++;
		}
		var->i++;
		if (var->i < nb_line && str[var->i][0] == '\n')
		{
			if (var->nb_tetris != 4 || var->lk < 3)
				return (1);
			var->nb_tetris = 0;
			var->lk = 0;
			var->i++;
		}
	}
	if (var->nb_tetris != 4 || var->lk < 3)
		return (1);
	return (0);
}

int		ft_check_link(char **str, int nb_line, int i, int j)
{
	int		link;

	link = 0;
	if (i + 1 < nb_line)
	{
		if (str[i + 1][j] == '#')
			link++;
	}
	if (str[i][j + 1] == '#')
		link++;
	return (link);
}
