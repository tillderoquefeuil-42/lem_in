/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:40:54 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/25 15:20:34 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "get_next_line.h"
#include "lem_in.h"

int		ft_passing(t_arg **arg)
{
	t_link	*tmp;
	char	*str;

	tmp = (*arg)->road;
	while (tmp->roomnbr != (*arg)->end)
		tmp = tmp->next;
	if (tmp->oqp == (*arg)->ants)
		return (1);
	while (tmp->roomnbr != (*arg)->road->next->roomnbr)
	{
		str = ft_roomfound(arg, tmp->roomnbr);
		tmp->oqp = tmp->prec->oqp;
		if (tmp->oqp != 0)
			ft_printf("L%d-%s ", tmp->oqp, str);
		tmp = tmp->prec;
		tmp->oqp = 0;
	}
	if (tmp->next->oqp != 0 && tmp->next->oqp < (*arg)->ants)
	{
		tmp->oqp = tmp->next->oqp + 1;
		str = ft_roomfound(arg, tmp->roomnbr);
		ft_printf("L%d-%s", tmp->oqp, str);
	}
	ft_printf("\n");
	return (ft_passing(arg));
}

int		ft_onepass(t_arg **arg)
{
	t_link	*tmp;
	char	*str;
	int		i;

	i = 1;
	tmp = (*arg)->road->next;
	str = ft_roomfound(arg, tmp->roomnbr);
	while (i <= (*arg)->ants)
	{
		ft_printf("L%d-%s ", i, str);
		i++;
	}
	ft_printf("\n");
	return (1);
}

int		ft_firstpass(t_arg **arg)
{
	t_link	*tmp;
	char	*str;

	if ((*arg)->ants > 0)
	{
		tmp = (*arg)->road->next;
		str = ft_roomfound(arg, tmp->roomnbr);
		tmp->oqp = 1;
		ft_printf("L%d-%s\n", tmp->oqp, str);
		return (1);
	}
	ft_printf("No Ants\n");
	return (0);
}

char	*ft_roomfound(t_arg **arg, int roomnbr)
{
	t_room	*tmp;

	tmp = (*arg)->lst;
	while (tmp->nbr != roomnbr)
		tmp = tmp->next;
	return (tmp->name);
}
