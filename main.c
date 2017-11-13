/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:28:28 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/13 18:53:31 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr("Error: Wrong arguments\n");
		return (0);
	}
	ft_read(av[1]);
	return (0);
}
