/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_projection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:51:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 11:51:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	camera_set_projection(t_camera *camera, t_mat4 *mat)
{
	ft_memcpy(&camera->projection, mat, sizeof(*mat));
}
