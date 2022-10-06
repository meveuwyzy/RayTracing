/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:22:10 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:22:13 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

int			skip_spaces(const char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	get_nmb(const char *str)
{
	size_t number;
	size_t order;
	size_t len;

	order = 1;
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	number = (int)(*str) - '0';
	while (order < len)
	{
		number = number * 10;
		order++;
	}
	if (order > 1)
		return ((int)(number + get_nmb(str + 1)));
	else
		return (number);
}

int			ft_atoi(const char *nptr)
{
	int sign;

	while (*nptr == ' ' || *nptr == '\v' || *nptr == '\r' \
		|| *nptr == '\t' || *nptr == '\n' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (ft_isdigit(*nptr))
		return (get_nmb(nptr) * sign);
	else
		raise_exception("Error while reading one of number", 33);
	return (0);
}

void		allocate(t_scene *scene)
{
	if (!(scene->camera = malloc(sizeof(t_camera *) * scene->cam_count)))
		exit(1);
	if (!(scene->light = malloc(sizeof(t_light *) * scene->l_count)))
		exit(1);
	if (!(scene->sphere = malloc(sizeof(t_sphere *) * scene->sp_count)))
		exit(1);
	if (!(scene->plane = malloc(sizeof(t_plane *) * scene->pl_count)))
		exit(1);
	if (!(scene->square = malloc(sizeof(t_square *) * scene->sq_count)))
		exit(1);
	if (!(scene->cylinder = malloc(sizeof(t_cylinder *) * scene->cy_count)))
		exit(1);
	if (!(scene->triangle = malloc(sizeof(t_triangle *) * scene->tr_count)))
		exit(1);
}
