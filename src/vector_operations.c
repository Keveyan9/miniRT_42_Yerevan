/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:20:59 by aivanyan          #+#    #+#             */
/*   Updated: 2023/06/10 15:32:59 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void vec_subtract(float c[3], float a[3], float b[3])
{
    int i;

    i = -1;
    while (++i < 3)
        c[i] = a[i] - b[i];
}

void vec_add(float c[3], float a[3], float b[3])
{
    int i;

    i = -1;
    while (++i < 3)
        c[i] = a[i] + b[i];
}

float dot_product(float a[3], float b[3])
{
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void cross(float c[3], float a[3], float b[3])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(float p[3])
{
    float len;

    len = sqrtf(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
    p[0] = p[0] / len;
    p[1] = p[1] / len;
    p[2] = p[2] / len;
}