/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:32:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 11:27:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_set_rotation(t_camera *camera, double x, double y, double z)
{
	t_mat4	rx;
	t_mat4	ry;
	t_mat4	rz;

	mat4_init_rotation_x(&rx, x);
	mat4_init_rotation_y(&ry, y);
	mat4_init_rotation_z(&rz, z);
	mat4_mult(&rz, &rz, &ry);
	mat4_mult(&rz, &rz, &rx);
	ft_memcpy(&camera->rotation, &rz, sizeof(rz));
}
