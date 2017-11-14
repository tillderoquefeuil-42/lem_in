/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:44:07 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/25 15:22:08 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf/ft_printf.h"

char	*ft_strndup(const char *s1, char c)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char*)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		ft_errorlem(0);
	while (s1[i] != c && s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strrndup(const char *s1, char c, int n)
{
	char	*s2;
	int		i;
	int		j;
	int		m;

	j = 0;
	m = 0;
	i = ft_strlen(s1);
	while (m != n && i > 0)
	{
		if (s1[i] == c)
			m++;
		i--;
	}
	s2 = (char*)malloc(sizeof(char) * (i));
	if (s2 == NULL)
		ft_errorlem(0);
	while (s1[j] && j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}

char	*ft_strrdup(const char *s1, char c, int n)
{
	char	*s2;
	int		i;
	int		j;
	int		m;

	j = 0;
	m = 0;
	i = ft_strlen(s1);
	while (m != n && i > 0)
	{
		if (s1[i - 1] == c)
			m++;
		i--;
	}
	m = ft_strlen(s1) - (++i);
	s2 = (char*)malloc(sizeof(char) * m);
	if (s2 == NULL)
		ft_errorlem(0);
	while (j < m)
	{
		s2[j] = s1[i++];
		j++;
	}
	s2[j] = 0;
	return (s2);
}

char	*ft_splitend(char *s)
{
	int		i;

	i = ft_strlen(s);
	while ((s[i] == 0 || s[i] == ' ') && i > 0)
		i--;
	i++;
	while (s[i] != 0)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
