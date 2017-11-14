/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:41:30 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/14 17:04:11 by aparabos         ###   ########.fr       */
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

int		ft_nbline(char *buffer)
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

char	**ft_storage(char *buffer)
{
	char	**str;
	size_t	i;

	i  = 0;
	str = ft_dimcor(buffer);
	ft_check(str, ft_nbline(buffer));
	ft_putstr("FT_CHECK PASS\n");
	str = ft_changechar(str);
	ft_putstr("FT_CHANGECHAR PASS\n");
	while (str[i])
		ft_putstr(str[i++]);
	return (str);
}

char		**ft_dimcor(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t  start;
	size_t	len;
	char	**dim;

	i = 0;
	len = 0;
	j = 0;
	if (!(dim = (char **)malloc(sizeof(char*) * ft_nbline(buffer) + 1)))
		return (NULL);
	while (buffer[i])
	{
		start = i;
		while (buffer[i] != '\n')
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
