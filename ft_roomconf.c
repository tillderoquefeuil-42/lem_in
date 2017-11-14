/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:27:00 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/22 15:21:45 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

int		ft_roomexist(t_arg **arg, char *str)
{
	t_room	*tmp;

	tmp = (*arg)->lst;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	addnewlink(t_link **begin, int i)
{
	t_link	*link;
	t_link	*tmp;

	link = (t_link*)malloc(sizeof(t_link));
	if (link == NULL)
		ft_errorlem(1);
	link->oqp = 0;
	link->roomnbr = i;
	link->next = NULL;
	if (*begin != NULL)
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = link;
		link->prec = tmp;
	}
	else
		*begin = link;
}
