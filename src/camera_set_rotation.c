/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:32:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 13:19:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_set_rotation(t_camera *camera, double x, double y, double z)
{
	t_mat4	rx;
	t_mat4	ry;
	t_mat4	rz;

	mat4_clear(&rx);
	mat4_clear(&ry);
	mat4_clear(&rz);
	mat4_init_rotation_x(&rx, x);
	mat4_init_rotation_y(&ry, y);
	mat4_init_rotation_z(&rz, z);
	rx = mat4_mult(&rx, &ry);
	rx = mat4_mult(&rx, &rz);
	rx = mat4_reverse(&rx);
	ft_memcpy(&camera->rotation.value, &rx.value, sizeof(rx.value));
	camera->view = mat4_mult(&camera->rotation, &camera->position);
}
