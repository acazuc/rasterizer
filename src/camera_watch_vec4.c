/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_watch_vec4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:24:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:13:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_watch_vec4(t_camera *camera, t_vec4 *vec)
{
	printf("1: x: %f, y: %f, z: %f, w: %f\n", vec->x, vec->y, vec->z, vec->w);
	mat4_dump(&camera->view);
	mat4_transform_vec4(&camera->view, vec);
	printf("2: x: %f, y: %f, z: %f, w: %f\n", vec->x, vec->y, vec->z, vec->w);
	mat4_transform_vec4(&camera->projection, vec);
	printf("3: x: %f, y: %f, z: %f, w: %f\n", vec->x, vec->y, vec->z, vec->w);
}
