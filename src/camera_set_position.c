/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:29:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 16:37:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_set_position(t_camera *camera, double x, double y, double z)
{
	mat4_clear(&camera->position);
	mat4_init_translation(&camera->position, -x, -y, -z);
}
