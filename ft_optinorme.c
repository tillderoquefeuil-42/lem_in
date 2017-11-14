/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optinorme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:22:12 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/25 16:27:23 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

void	ft_optinorme(t_arg **arg, t_room **tmproom, t_link **tmplink, int **rb)
{
	if (ft_roomused((*rb), (*arg)->r, (*tmplink)) == 0)
	{
		(*tmproom) = (*arg)->lst;
		while ((*tmproom)->nbr != (*tmplink)->roomnbr)
			(*tmproom) = (*tmproom)->next;
		(*tmplink) = (*tmproom)->link;
		if ((*arg)->print == 0)
			addnewlink(&(*arg)->road, (*tmproom)->nbr);
	}
}
