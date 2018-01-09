/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:54:25 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/22 17:03:16 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 545

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

typedef struct		s_var
{
	int				i;
	int				j;
	int				nb_tetris;
	int				lk;
}					t_var;

size_t				ft_nbtetris(char *buffer);
size_t				ft_countline(char *buffer, char c);

int					ft_strlen(char *str);
int					ft_error(char *str, int fd);
int					ft_check_tetris_total(char **str, int nb_line);
int					ft_check_char(char **str, int nb_line);
int					ft_check_tetris_number(char **str, int nb_line, t_var *var);
int					ft_check_size(char **str, int nb_line);
int					ft_check_link(char **str, int nb_lines, int i, int j);
int					ft_nbline(char *buffer);
int					ft_findspaces(int i, int j, char **res, t_list *lst);
int					ft_solver(char **res, t_list *lst, int pos);
int					ft_needrealloc(char **res, t_list *lst, t_list *tmp);

char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcpy(char *dest, const char *src);

char				**ft_dimcor(char *buffer);
char				**ft_callfunction(char *buffer);
char				**ft_strsplit(char const *s, char c);
char				**ft_changechar(char **str, int nb_line);
char				**ft_mapgen(t_list *lst);
char				**ft_emptymap(char **res, int len);
char				**ft_maprealloc(char **res);
char				**ft_putpiece(char **res, t_list *lst, int i, int j);
char				**ft_dellasttetris(char **res, t_list *lst);
char				**ft_genforx(char **res, int len);
char				**ft_genfory(char **res, int len);

void				ft_check(char **str, int nb_line);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putlst(t_list *lst);
void				ft_read(char *av);
void				ft_putnbr(int nb);
void				ft_lstaddend(t_list **lst, t_list *new);
void				ft_coord(char **str, t_list **lst, int nb_line);
void				ft_putcoord(t_list **lst);
void				ft_lststock(char **str, t_list *lst);
void				ft_putpieces(t_list *lst);
void				ft_showmap(char **res);
void				ft_freemap(char **res);
void				ft_checkend(t_list *lst, char **res);
void				ft_setcoord(t_list **lst);
void				ft_changecoord(t_list **lst, char **str, int i, int j);

t_list				*ft_lstnew(t_list *lst);

#endif
