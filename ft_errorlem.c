/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:14:08 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/08 11:27:49 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_errorlem(int i)
{
	if (i == 0)
		write(2, "Error00\nMalloc Failed\n", 22);
	if (i == 1)
		write(2, "Error01\nToo many arguments\n", 27);
	if (i == 2)
		write(2, "Error02\nBad Number of Ants\n", 27);
	if (i == 3)
		write(2, "Error03\nBad Roomname or coordinates\n", 36);
	if (i == 4)
		write(2, "Error04\nEmpty File\n", 20);
	if (i == 5)
		write(2, "Error05\nNo Rooms\n", 18);
	if (i == 6)
		write(2, "Error06\nStart room and End's one are the same\n", 46);
	if (i == 7)
		write(2, "Error07\nBad Start or End\n", 26);
	exit(0);
}
