/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:19:28 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 21:06:31 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"
#include "include/get_next_line.h"

static int	save_img(t_scene *scene, t_rt *rt)
{
	t_canvas *canvas;

	canvas = render(scene, scene->selected_camera_index);
	put_pixels_into_image(scene, canvas, rt->img);
	save_bmp((unsigned char *)rt->img.addr, scene->res_x, scene->res_y);
	exit(0);
}

int			main(int argc, char *argv[])
{
	t_scene		*scene;
	t_canvas	*canvas;
	t_rt		rt;

	if (argc < 2 || argc > 3)
		return (1);
	scene = new_scene(argv[1]);
	rt.scene = scene;
	rt.mlx.mlx = mlx_init();
	rt.img.img = mlx_new_image(rt.mlx.mlx, scene->res_x, scene->res_y);
	rt.img.addr = mlx_get_data_addr(
			rt.img.img, &rt.img.bpp, &rt.img.line_lenght, &rt.img.endian);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		return (save_img(scene, &rt));
	else if (argc == 3)
		exit(1);
	rt.mlx.win = mlx_new_window(rt.mlx.mlx, scene->res_x, scene->res_y, "RT");
	mlx_hook(rt.mlx.win, 2, 1Lu << 0u, keypress, &rt);
	mlx_hook(rt.mlx.win, 17, 1Lu << 17u, red_cross_click, &rt.mlx);
	canvas = render(scene, scene->selected_camera_index);
	put_pixels_into_image(scene, canvas, rt.img);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win, rt.img.img, 0, 0);
	mlx_loop(rt.mlx.mlx);
	return (0);
}
