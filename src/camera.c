/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:02:27 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:02:31 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_camera		*new_camera(t_vec *pos, t_vec *orient, double fov)
{
	t_camera *result;

	if (!(result = malloc(sizeof(t_camera))))
		exit(EXIT_FAILURE);
	result->pos = pos;
	result->orient = orient;
	result->fov = fov;
	result->destroy = camera_destructor;
	return (result);
}

void			camera_destructor(t_camera *self)
{
	self->pos->destroy(self->pos);
	self->orient->destroy(self->orient);
	free(self);
}
