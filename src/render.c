/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:23:48 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:23:49 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_canvas	*render(t_scene *scene, int camera_index)
{
	int			width;
	int			height;
	t_canvas	*canvas;
	t_color		*color;

	width = scene->res_x;
	height = scene->res_y;
	canvas = new_canvas(width, height);
	scene->camera[camera_index]->distance_to_viewport = (double)width /
			(2. * tan(scene->camera[camera_index]->fov * M_PI / 360.));
	write(1, "Please, wait..\n", 15);
	while (height--)
	{
		width = scene->res_x;
		while (width--)
		{
			if (!(color = raytrace(width, height, scene, camera_index)))
				return (NULL);
			canvas->set_pixel(canvas, width, height, color);
		}
	}
	write(1, "Done!\n", 6);
	return (canvas);
}
