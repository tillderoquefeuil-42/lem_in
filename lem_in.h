/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:17:38 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 11:28:19 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_link
{
	int				roomnbr;
	int				oqp;
	struct s_link	*next;
	struct s_link	*prec;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				nbr;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_arg
{
	int				start;
	int				end;
	int				sande;
	int				rooms;
	int				ants;
	t_room			*lst;
	int				i;
	int				*rb;
	int				r;
	int				print;
	t_link			*road;
}					t_arg;

void				ft_errorlem(int i);
char				*ft_strndup(const char *s1, char c);
char				*ft_strrdup(const char *s1, char c, int n);
char				*ft_strrndup(const char *s1, char c, int n);
t_arg				*ft_initlem(int c);
t_arg				*ft_initarg(t_arg **arg);
int					ft_initc(int c, char *str, int t);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_iscoord(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					*ft_tabccpy(int *tab, int size, int m);
int					ft_detector(char *str, t_arg **arg);
int					ft_nbrant(t_arg **arg, char *str);
int					ft_roomname(t_arg **arg, char *str);
int					ft_roomlink(t_arg **arg, char *str);
int					ft_other(t_arg **arg, char *str);
t_room				*ft_lstnew(char *str, int i);
void				ft_lstadd(t_room **begin, t_room *new);
void				ft_lstprint(t_room *lst, int t);
void				ft_linkprint(t_link *lst);
int					ft_roomexist(t_arg **arg, char *str);
void				addnewlink(t_link **begin, int i);
int					ft_reso(t_arg **arg);
void				ft_nextroom(t_arg **arg, t_room *tmproom,
						t_link *tmplink, int *rb);
int					ft_roomused(int *tab, int m, t_link *tmplink);
void				ft_roadprint(t_link *lst);
int					ft_firstpass(t_arg **arg);
int					ft_passing(t_arg **arg);
int					ft_onepass(t_arg **arg);
char				*ft_roomfound(t_arg **arg, int roomnbr);
int					ft_opth(t_arg **arg, t_room *tmproom,
						t_link *tmplink, int *rb);
t_link				*ft_multipath(t_arg **arg, t_room *tmproom,
						t_link *tmplink, int *rb);
void				ft_printroomused(t_arg **arg, int *tab);
char				*ft_splitend(char *s);
void				ft_cleaner(t_arg **arg);
void				ft_linkcleaner(t_link *tmplink);
void				ft_strcleaner(char *str);
int					ft_endisnext(t_arg **arg, t_link **tmp, t_link *tmplink);
void				ft_gp(int c, int *n, t_link **tmplink, t_link *tmp);
void				ft_inivalue(t_arg **arg, int *c, int *j, int *o);
void				ft_endwhilevalue(t_arg **arg, int j, int o, int *tab);
void				ft_addintab(t_arg **arg, int **tab, int linknbr,
						t_room **tmproom);
void				ft_optinorme(t_arg **arg, t_room **tmproom,
						t_link **tmplink, int **rb);
void				ft_checkarg(t_arg **arg);

#endif
