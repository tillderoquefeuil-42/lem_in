/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfounder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:55:09 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 11:46:34 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

int		ft_opth(t_arg **arg, t_room *tmproom, t_link *tmplink, int *rb)
{
	if ((*arg)->i <= 0)
		return ((*arg)->i);
	if (tmplink == NULL)
		return (0);
	while (ft_roomused(rb, (*arg)->r, tmplink) == 1 && tmplink->next != NULL)
		tmplink = tmplink->next;
	if (ft_roomused(rb, (*arg)->r, tmplink) == 1 && tmplink->next == NULL)
		return (0);
	else if (ft_roomused(rb, (*arg)->r, tmplink) == 0 && tmplink->next != NULL)
	{
		tmplink = ft_multipath(arg, tmproom, tmplink, rb);
		if (tmplink == NULL)
			return (0);
	}
	ft_optinorme(arg, &tmproom, &tmplink, &rb);
	if (tmproom->nbr == (*arg)->end)
		return ((*arg)->i);
	else if (ft_roomused(rb, (*arg)->r, tmplink) == 1 && tmplink->next == NULL)
		return (0);
	rb[(*arg)->r++] = tmproom->nbr;
	(*arg)->i++;
	if (ft_opth(arg, tmproom, tmplink, rb) == 0)
		return (0);
	else
		return ((*arg)->i);
}

t_link	*ft_multipath(t_arg **arg, t_room *tmproom, t_link *tmplink, int *rb)
{
	t_link	*tmp;
	int		*tab;
	int		j;
	int		o;
	int		c;

	if (ft_endisnext(arg, &tmp, tmplink) == 1)
		return (tmp);
	ft_inivalue(arg, &c, &j, &o);
	while (tmp != NULL)
	{
		tab = ft_tabccpy(rb, (*arg)->rooms, (*arg)->r);
		if (ft_roomused(rb, (*arg)->r, tmp) == 0)
		{
			ft_addintab(arg, &tab, tmp->roomnbr, &tmproom);
			ft_gp(ft_opth(arg, tmproom, tmproom->link, tab), &c, &tmplink, tmp);
		}
		ft_endwhilevalue(arg, j, o, tab);
		tmp = tmp->next;
	}
	(*arg)->print--;
	if (c > 0 && tmp == NULL)
		return (tmplink);
	else
		return (NULL);
}

void	ft_inivalue(t_arg **arg, int *c, int *j, int *o)
{
	(*c) = (*arg)->rooms;
	(*j) = (*arg)->i;
	(*o) = (*arg)->r;
}

void	ft_gp(int c, int *n, t_link **tmplink, t_link *tmp)
{
	if (c > 0 && c < *n)
	{
		*n = c;
		(*tmplink) = tmp;
	}
}

int		ft_endisnext(t_arg **arg, t_link **tmp, t_link *tmplink)
{
	(*tmp) = tmplink;
	(*arg)->print++;
	while ((*tmp) != NULL)
	{
		if ((*tmp)->roomnbr == (*arg)->end)
		{
			(*arg)->print--;
			return (1);
		}
		(*tmp) = (*tmp)->next;
	}
	(*tmp) = tmplink;
	return (0);
}
