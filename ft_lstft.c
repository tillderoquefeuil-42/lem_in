/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:49:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/22 15:47:25 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf/ft_printf.h"

t_room	*ft_lstnew(char *str, int i)
{
	t_room	*lst;

	lst = (t_room*)malloc(sizeof(t_room));
	if (lst == NULL)
		ft_errorlem(1);
	lst->link = NULL;
	lst->name = str;
	lst->nbr = i;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd(t_room **begin, t_room *new)
{
	t_room	*tmp;

	if (*begin != NULL)
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin = new;
}

void	ft_lstprint(t_room *lst, int t)
{
	t_room	*tmp;
	t_room	*tmp2;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_putstr(tmp2->name);
			if (tmp != NULL && t == 0)
				ft_putstr(" | ");
			else if (t == 1)
				ft_linkprint(tmp2->link);
		}
	}
	ft_putchar('\n');
}

void	ft_linkprint(t_link *lst)
{
	t_link	*tmp;
	t_link	*tmp2;

	if (lst)
	{
		ft_putstr(" : ");
		tmp = lst;
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_putnbr(tmp2->roomnbr);
			if (tmp != NULL)
				ft_putstr(" | ");
		}
	}
	ft_putchar('\n');
}

void	ft_roadprint(t_link *lst)
{
	t_link	*tmp;
	t_link	*tmp2;

	if (lst)
	{
		ft_putstr("Road = ");
		tmp = lst;
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_putnbr(tmp2->roomnbr);
			if (tmp != NULL)
				ft_putstr(" | ");
		}
	}
	ft_putchar('\n');
}
