/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:24:47 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 05:24:49 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TRACING_H
# define MINIRT_TRACING_H
# include "canvas.h"
# include "vectors.h"
# include "scene.h"

typedef struct	s_flag
{
	char		type;
	double		t;
	int			index;
}				t_flag;

t_color			*raytrace(int cnv_x, int cnv_y, t_scene *scene, int cam_ind);
t_vec			*ray_cast(int cx, int cy, t_scene *scene, int camera_index);
t_vec			*intersect(t_scene *scn, t_object *obj, t_vec *o, t_vec *d);
void			int_with_sp(t_flag *flag, t_scene *scn, t_vec *o, t_vec *d);
void			int_with_pl(t_flag *flag, t_scene *scn, t_vec *o, t_vec *d);
void			int_with_cy(t_flag *flag, t_scene *scn, t_vec *o, t_vec *d);
void			int_with_sq(t_flag *flag, t_scene *scn, t_vec *o, t_vec *d);
void			int_with_tr(t_flag *flag, t_scene *scn, t_vec *o, t_vec *d);

#endif
