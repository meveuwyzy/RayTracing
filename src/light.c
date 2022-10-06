/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:19:08 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:19:12 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_light			*new_light(t_vec *pos, t_color *color, double brightness)
{
	t_light *result;

	if (!(result = malloc(sizeof(t_light))))
		exit(EXIT_FAILURE);
	result->pos = pos;
	result->color = color;
	result->brightness = brightness;
	result->destroy = light_destructor;
	return (result);
}

void			light_destructor(t_light *self)
{
	self->color->destroy(self->color);
	self->pos->destroy(self->pos);
	free(self);
}

t_amblight		*new_amblight(t_color *color, double ratio)
{
	t_amblight *result;

	if (!(result = malloc(sizeof(t_amblight))))
		exit(EXIT_FAILURE);
	result->color = color;
	result->ratio = ratio;
	result->destroy = amblight_destructor;
	return (result);
}

void			amblight_destructor(t_amblight *self)
{
	self->color->destroy(self->color);
	free(self);
}
