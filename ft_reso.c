/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:57:41 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 11:43:20 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

int		ft_reso(t_arg **arg)
{
	t_room	*tmproom;
	t_link	*tmplink;
	int		c;

	(*arg)->rb = (int*)malloc(sizeof(int) * (*arg)->rooms);
	if (!(*arg)->rb)
		ft_errorlem(0);
	tmproom = (*arg)->lst;
	while (tmproom->nbr != (*arg)->start)
		tmproom = tmproom->next;
	(*arg)->rb[(*arg)->r] = tmproom->nbr;
	(*arg)->r = (*arg)->r + 1;
	tmplink = tmproom->link;
	addnewlink(&(*arg)->road, tmproom->nbr);
	c = ft_opth(arg, tmproom, tmplink, (*arg)->rb);
	return (c);
}

void	ft_addintab(t_arg **arg, int **tab, int linknbr, t_room **tmproom)
{
	(*tmproom) = (*arg)->lst;
	while ((*tmproom)->nbr != linknbr)
		(*tmproom) = (*tmproom)->next;
	(*tab)[(*arg)->r] = (*tmproom)->nbr;
	(*arg)->r++;
	(*arg)->i++;
}

void	ft_endwhilevalue(t_arg **arg, int j, int o, int *tab)
{
	if (tab)
		free(tab);
	(*arg)->i = j;
	(*arg)->r = o;
}

int		ft_roomused(int *tab, int m, t_link *tmplink)
{
	int	j;

	j = 0;
	while (j < m)
	{
		if (tab[j] == tmplink->roomnbr)
			return (1);
		j++;
	}
	return (0);
}

int		*ft_tabccpy(int *tab, int size, int m)
{
	int	i;
	int	*newtab;

	i = 0;
	newtab = (int*)malloc(sizeof(int) * size);
	if (!newtab)
		ft_errorlem(0);
	while (i < m)
	{
		newtab[i] = tab[i];
		i++;
	}
	return (newtab);
}
