/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:20:04 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/25 14:50:17 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf/ft_printf.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	else if (c == 43)
		return (1);
	else
		return (0);
}

int	ft_iscoord(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (47 < str[i] && str[i] < 58)
		i++;
	if (str[i] == ' ')
	{
		i++;
		while (47 < str[i] && str[i] < 58)
			i++;
		if (str[i] == 0)
			r = 0;
	}
	return (r);
}
