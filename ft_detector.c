/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:49:57 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 13:55:36 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

int	ft_detector(char *str, t_arg **arg)
{
	int		i;
	char	*s;

	i = 0;
	str = ft_splitend(str);
	if (ft_strcmp(str, "") == 0)
		return (0);
	s = ft_strrdup(str, ' ', 2);
	if (ft_iscoord(s) == 0)
		return (2);
	while (ft_isalnum(str[i]) == 1 || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (3);
	else if (str[i] == 0 && (*arg)->rooms == 0)
		return (1);
	else
		return (0);
}

int	ft_nbrant(t_arg **arg, char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
		c = c + ft_isdigit(str[i++]);
	if (c == i)
	{
		(*arg)->ants = ft_atoi(str);
		return (0);
	}
	ft_errorlem(2);
	return (1);
}

int	ft_roomname(t_arg **arg, char *str)
{
	char	*s;
	t_room	*newroom;

	s = ft_strrdup(str, ' ', 2);
	if (ft_iscoord(s) == 0)
	{
		s = ft_strrndup(str, ' ', 2);
		if (ft_roomexist(arg, s) == 1)
			ft_errorlem(3);
		newroom = ft_lstnew(s, (*arg)->rooms);
		ft_lstadd(&(*arg)->lst, newroom);
		(*arg)->rooms = (*arg)->rooms + 1;
		return (0);
	}
	ft_strcleaner(s);
	return (1);
}

int	ft_roomlink(t_arg **arg, char *str)
{
	char	*s1;
	char	*s2;
	t_room	*tmp;
	t_room	*tmp2;

	s1 = ft_strndup(str, '-');
	s2 = ft_strrdup(str, '-', 1);
	if (ft_roomexist(arg, s1) == 0 || ft_roomexist(arg, s2) == 0)
	{
		ft_strcleaner(s1);
		ft_strcleaner(s2);
		return (1);
	}
	tmp = (*arg)->lst;
	tmp2 = (*arg)->lst;
	while (ft_strcmp(tmp->name, s1) != 0 && tmp != NULL)
		tmp = tmp->next;
	while (ft_strcmp(tmp2->name, s2) != 0 && tmp2 != NULL)
		tmp2 = tmp2->next;
	if (tmp == NULL || tmp2 == NULL)
		ft_errorlem(0);
	addnewlink(&tmp->link, tmp2->nbr);
	addnewlink(&tmp2->link, tmp->nbr);
	return (0);
}

int	ft_other(t_arg **arg, char *str)
{
	if (ft_strcmp(str, "##start") == 0)
	{
		(*arg)->start = (*arg)->rooms;
		(*arg)->sande = (*arg)->sande + 1;
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		(*arg)->end = (*arg)->rooms;
		(*arg)->sande = (*arg)->sande - 1;
	}
	else if (str[0] != '#')
		return (1);
	return (0);
}
