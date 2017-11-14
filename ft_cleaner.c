/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:05:53 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/25 15:06:46 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lem_in.h"

void	ft_cleaner(t_arg **arg)
{
	t_room	*tmproom;
	t_room	*tmproom2;
	t_link	*tmplink;

	tmplink = (*arg)->road;
	ft_linkcleaner(tmplink);
	tmproom = (*arg)->lst;
	while (tmproom != NULL)
	{
		tmproom2 = tmproom;
		tmproom = tmproom->next;
		ft_linkcleaner(tmproom2->link);
		ft_strcleaner(tmproom2->name);
		if (tmproom2)
		{
			free(tmproom2);
			tmproom2->next = NULL;
		}
	}
	if ((*arg)->rb)
		free((*arg)->rb);
	if (*arg)
		free(*arg);
}

void	ft_linkcleaner(t_link *tmplink)
{
	t_link	*tmplink2;

	while (tmplink != NULL)
	{
		tmplink2 = tmplink;
		tmplink = tmplink->next;
		if (tmplink2)
		{
			free(tmplink2);
			tmplink2->next = NULL;
		}
	}
}

void	ft_strcleaner(char *str)
{
	if (str)
		free(str);
}
