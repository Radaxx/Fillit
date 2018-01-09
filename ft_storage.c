/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:41:30 by aparabos          #+#    #+#             */
/*   Updated: 2017/12/01 14:37:39 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_nbtetris(char *buffer)
{
	size_t	i;
	size_t	nb_tetris;

	i = 0;
	nb_tetris = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] == '\n')
			nb_tetris++;
		i++;
	}
	nb_tetris++;
	return (nb_tetris);
}

int			ft_nbline(char *buffer)
{
	int		i;
	int		nb_line;

	i = 0;
	nb_line = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			nb_line++;
		i++;
	}
	return (nb_line);
}

void		ft_check(char **str, int nb_line)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.nb_tetris = 0;
	var.lk = 0;
	if ((ft_check_size(str, nb_line)) == 1)
		ft_error("error\n", 1);
	if ((ft_check_char(str, nb_line)) == 1)
		ft_error("error\n", 1);
	if ((ft_check_tetris_number(str, nb_line, &var)) == 1)
		ft_error("error\n", 1);
}

char		**ft_dimcor(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;
	char	**dim;

	i = 0;
	len = 0;
	j = 0;
	if (!(dim = (char **)malloc(sizeof(char *) * ft_nbline(buffer) + 1)))
		return (NULL);
	while (buffer[i])
	{
		start = i;
		while (buffer[i] && buffer[i] != '\n')
		{
			len++;
			i++;
		}
		dim[j] = ft_strsub(buffer, start, len + 1);
		len = 0;
		j++;
		i++;
	}
	return (dim);
}
