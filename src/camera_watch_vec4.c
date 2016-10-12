/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_watch_vec4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:24:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 12:42:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_watch_vec4(t_camera *camera, t_vec4 *vec4)
{
	ft_putendl("view:");
	mat4_dump(&camera->view);
	ft_putendl("\nprojection:");
	mat4_dump(&camera->projection);
	mat4_transform_vec4(&camera->view, vec4);
	mat4_transform_vec4(&camera->projection, vec4);
}
