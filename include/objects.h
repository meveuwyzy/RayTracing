/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:24:25 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 05:24:28 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H
# include "vectors.h"
# include "canvas.h"

typedef	struct	s_sphere
{
	t_vec		*pos;
	t_color		*color;
	double		diameter;
	t_vec		*(* get_normal)(struct s_sphere *self, t_vec *intersect_p);
	double		(* intersection)(t_vec *o, t_vec *d, struct s_sphere *sphere);
	void		(* destroy)(struct s_sphere *self);
}				t_sphere;

t_sphere		*new_sphere(t_vec *pos, t_color *color, double d);
t_vec			*get_sphere_normal(struct s_sphere *self, t_vec *intersect_p);
double			sphere_intersection(t_vec *o, t_vec *d, t_sphere *sphere);
void			sphere_destructor(t_sphere *self);

typedef struct	s_plane
{
	t_vec		*pos;
	t_color		*color;
	t_vec		*normal_vector;
	t_vec		*(* get_normal)(struct s_plane *self);
	double		(* intersection)(t_vec *o, t_vec *d, struct s_plane *plane);
	void		(* destroy)(struct s_plane *self);
}				t_plane;

t_plane			*new_plane(t_vec *pos, t_vec *normal, t_color *color);
t_vec			*get_plane_normal(t_plane *self);
double			plane_intersection(t_vec *o, t_vec *d, t_plane *plane);
void			plane_destructor(t_plane *self);

typedef struct	s_square
{
	t_vec		*pos;
	t_color		*color;
	t_vec		*normal_vector;
	t_vec		*(* get_normal)(struct s_square *self);
	double		(* intersection)(t_vec *o, t_vec *d, struct s_square *square);
	void		(* destroy)(struct s_square *self);
	double		side_size;
}				t_square;

t_square		*new_square(
		t_vec *pos, t_vec *norm, t_color *color, double side_size);
t_vec			*get_square_normal(t_square *self);
double			square_intersection(t_vec *o, t_vec *d, t_square *square);
void			square_destructor(t_square *self);

typedef struct	s_cylinder
{
	t_vec		*pos;
	t_color		*color;
	t_vec		*norm;
	double		diameter;
	t_vec		*(* get_normal)(struct s_cylinder *self, t_vec *intersect_p);
	double		(* intersection)(t_vec *o, t_vec *d, struct s_cylinder *cy);
	void		(* destroy)(struct s_cylinder *self);
}				t_cylinder;

t_cylinder		*new_cylinder(t_vec *pos, t_vec *norm, t_color *clr, double d);
t_vec			*get_cylinder_normal(t_cylinder *self, t_vec *intersection_p);
double			cylinder_intersection(t_vec *o, t_vec *d, t_cylinder *cy);
void			cylinder_destructor(t_cylinder *self);

typedef struct	s_triangle
{
	t_vec		*pos;
	t_color		*color;
	t_vec		*normal_vector;
	t_vec		*(* get_normal)(struct s_triangle *self);
	double		(* intersection)(t_vec *o, t_vec *d, struct s_triangle *tr);
	void		(* destroy)(struct s_triangle *self);
	t_vec		*e1;
	t_vec		*e2;
}				t_triangle;

t_triangle		*new_triangle(t_vec *p1, t_vec *p2, t_vec *p3, t_color *color);
t_vec			*get_triangle_normal(t_triangle *self);
double			triangle_intersection(t_vec *o, t_vec *d, t_triangle *tr);
void			triangle_destructor(t_triangle *self);

typedef struct	s_object
{
	int			exist;
	double		t;
	t_color		*color;
	t_vec		*normal_vec;
	void		(* destroy)(struct s_object *self);
}				t_object;

t_object		*new_object();
void			object_destructor(t_object *self);
double			choice(double t1, double t2, double t_min, double t_max);

#endif
