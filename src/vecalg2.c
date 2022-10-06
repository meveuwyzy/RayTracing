/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecalg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:26:21 by dalonso           #+#    #+#             */
/*   Updated: 2020/11/17 03:26:24 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vectors.h"

t_vec		*vec_sum(t_vec *vec1, t_vec *vec2, t_vec *buf)
{
	buf->x = vec1->x + vec2->x;
	buf->y = vec1->y + vec2->y;
	buf->z = vec1->z + vec2->z;
	return (buf);
}

t_vec		*vec_diff(t_vec *vec1, t_vec *vec2, t_vec *buf)
{
	buf->x = vec1->x - vec2->x;
	buf->y = vec1->y - vec2->y;
	buf->z = vec1->z - vec2->z;
	return (buf);
}

t_vec		*multiplication_by_scalar(
		t_vec *vec, double scalar, t_vec *buf)
{
	buf->x = (vec->x) * scalar;
	buf->y = (vec->y) * scalar;
	buf->z = (vec->z) * scalar;
	return (buf);
}

t_vec		*cross_product(t_vec *u, t_vec *v)
{
	t_vec	*p;

	p = new_vector(0, 0, 0);
	p->x = v->z * u->y - v->y * u->z;
	p->y = v->x * u->z - v->z * u->x;
	p->z = v->y * u->x - v->x * u->y;
	return (p);
}
