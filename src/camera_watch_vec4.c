/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_watch_vec4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:24:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 11:56:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_watch_vec4(t_camera *camera, t_vec4 *vec)
{
	mat4_transform_vec4(&camera->rotation, vec);
	mat4_transform_vec4(&camera->position, vec);
	mat4_transform_vec4(&camera->projection, vec);
	if (vec->z != 0)
	{
		vec->x /= vec->z;
		vec->y /= vec->z;
	}
}
