/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:54:25 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/14 17:17:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 105

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			**piece;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
}					t_list;

size_t				ft_nbtetris(char *buffer);
size_t				ft_countline(char *buffer, char c);

int					ft_strlen(char *str);
int					ft_error(char *str, int fd);
int					ft_check_char(char **str, int nb_line);
int					ft_check_tetris_number(char **str, int nb_line);
int					ft_check_size(char **str, int nb_line);
int					ft_check(char **str, int nb_line);
int					ft_nbline(char *buffer);

char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				**ft_dimcor(char *buffer);
char				**ft_storage(char *buffer);
char				**ft_strsplit(char const *s, char c);
char				**ft_changechar(char **str);

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putlst(t_list *lst);
void				ft_read(char *av);
void				ft_putnbr(int nb);

#endif
