/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:40:06 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 11:34:58 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "get_next_line.h"
#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;
	int		c;

	if (argc > 1 && argv)
		ft_errorlem(1);
	arg = ft_initlem(0);
	ft_checkarg(&arg);
	c = ft_reso(&arg);
	ft_printf("\n");
	if (c == 1 && arg->ants != 0)
		ft_onepass(&arg);
	else if (c != 0)
	{
		if (ft_firstpass(&arg) == 1)
			ft_passing(&arg);
	}
	else
		ft_printf("/!\\ No solutions /!\\\n");
	ft_cleaner(&arg);
	ft_printf("\nEnd Of Lem-In.\n");
	return (0);
}
