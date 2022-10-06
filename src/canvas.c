/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:17:27 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:17:31 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas.h"

t_canvas		*new_canvas(int width, int height)
{
	t_canvas	*result;
	t_color		**pixel_array;

	if (!(result = malloc(sizeof(t_canvas))))
		exit(EXIT_FAILURE);
	if (!(pixel_array = malloc(width * height * sizeof(t_color *))))
		exit(EXIT_FAILURE);
	result->width = width;
	result->height = height;
	result->pixel_array = pixel_array;
	result->set_pixel = set_pixel;
	result->get_pixel = get_pixel;
	result->destroy = canvas_destructor;
	return (result);
}

t_color			*get_pixel(struct s_canvas *self, int x, int y)
{
	int index;

	index = (y * self->width) + x;
	return (self->pixel_array[index]);
}

void			set_pixel(struct s_canvas *self, int x, int y, t_color *color)
{
	int index;

	index = (y * self->width) + x;
	self->pixel_array[index] = color;
}

void			canvas_destructor(struct s_canvas *self)
{
	int len;

	len = self->width * self->height;
	while (len--)
		self->pixel_array[len]->destroy(self->pixel_array[len]);
	free(self->pixel_array);
	free(self);
}
