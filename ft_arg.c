/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:59:11 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 14:06:43 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "get_next_line.h"
#include "lem_in.h"

t_arg	*ft_initlem(int c)
{
	t_arg		*arg;
	char		*str;
	static int	(*lstft[4])(t_arg **arg, char *str) =
	{ft_other, ft_nbrant, ft_roomname, ft_roomlink};

	arg = ft_initarg(&arg);
	while (c == 0 && get_next_line(0, &str) != 0)
	{
		if (ft_detector(str, &arg) == 0 || ft_detector(str, &arg) == 1)
			c = (*lstft[ft_detector(str, &arg)])(&arg, str);
		else
			ft_errorlem(2);
		ft_printf("%s\n", str);
		if (ft_detector(str, &arg) == 1 && c == 0)
			c = -1;
	}
	if (ft_strcmp(str, "") == 0)
		ft_errorlem(4);
	c = ft_initc(c, str, 0);
	while (get_next_line(0, &str) != 0 && c == 0)
		c = ft_initc((*lstft[ft_detector(str, &arg)])(&arg, str), str, 1);
	return (arg);
}

int		ft_initc(int c, char *str, int t)
{
	if (c == -1 && t == 0)
		c = 0;
	else if (c == 0 && t == 1)
		ft_printf("%s\n", str);
	ft_strcleaner(str);
	return (c);
}

t_arg	*ft_initarg(t_arg **arg)
{
	*arg = (t_arg*)malloc(sizeof(t_arg));
	if (!*arg)
		ft_errorlem(0);
	(*arg)->lst = NULL;
	(*arg)->road = NULL;
	(*arg)->start = -1;
	(*arg)->end = -2;
	(*arg)->rooms = 0;
	(*arg)->ants = 0;
	(*arg)->i = 1;
	(*arg)->r = 0;
	(*arg)->rb = 0;
	(*arg)->print = 0;
	(*arg)->sande = 0;
	return (*arg);
}

void	ft_checkarg(t_arg **arg)
{
	if ((*arg)->lst == NULL)
		ft_errorlem(5);
	if ((*arg)->start == (*arg)->end)
		ft_errorlem(6);
	if ((*arg)->sande != 0)
		ft_errorlem(7);
	if ((*arg)->start < 0 || (*arg)->end < 0)
		ft_errorlem(7);
}
