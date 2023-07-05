/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorRay.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:20:16 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/05 19:20:19 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTORRAY_H
# define VECTORRAY_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_ray
{
	float	t;
	t_vec	orig;
	t_vec	dir;
}	t_ray;

t_vec	vecAdd(t_vec a, t_vec b);
t_vec	vecSub(t_vec a, t_vec b);
float	dotProduct(t_vec a, t_vec b);
t_vec	cross(t_vec a, t_vec b);
t_vec	normalize(t_vec p);
t_vec	vecScale(float n, t_vec p);
float	distance(t_vec p1, t_vec p2);
float	vecNorm(t_vec vec);
t_vec	vecMul(t_vec v, float f);
t_vec	vecInverse(t_vec v);

#endif
