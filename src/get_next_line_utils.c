/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:06:30 by student           #+#    #+#             */
/*   Updated: 2020/11/17 06:43:59 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1 = s1 + 1;
		s2 = s2 + 1;
		i++;
	}
	return (0);
}

char		*ft_glue(char *between, char *buff, int *flag)
{
	char	*out;
	int		i;
	int		l1;
	int		l2;

	l1 = ft_strlen(between);
	l2 = ft_strlen(buff);
	if (!(out = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
	{
		*flag = -1;
		return (NULL);
	}
	out[l1 + l2] = '\0';
	i = 0;
	while (between && *between)
		out[i++] = *between++;
	while (buff && *buff)
		out[i++] = *buff++;
	return (out);
}
