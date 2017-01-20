/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_watch_vertex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:24:29 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:20:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_watch_vertex(t_vec4 *vec)
{
	mat4_transform_vec4(&g_ctx->modelview_matrix[g_ctx->modelview_stack_depth], vec);
	mat4_transform_vec4(&g_ctx->projection_matrix[g_ctx->projection_stack_depth], vec);
	if (vec->w != 0)
	{
		vec->x /= vec->w;
		vec->y /= vec->w;
		vec->z /= vec->w;
	}
	vec->x = round(g_ctx->width / 2 + vec->x * g_ctx->width / 2);
	vec->y = round(g_ctx->height / 2 + vec->y * g_ctx->height / 2);
}
