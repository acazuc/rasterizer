/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_ctx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:49 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 12:53:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx = NULL;

static void	init_2(t_ftg_ctx *ctx)
{
	ctx->color_array_stride = 0;
	ctx->color_array_pointer = NULL;
}

void		ftg_ctx_init(t_ftg_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
	mat4_init_identity(&ctx->projection_matrix[0]);
	mat4_init_identity(&ctx->modelview_matrix[0]);
	ftg_viewport(0, 0);
	ctx->projection_max_stack_depth = PROJECTION_MAX_STACK_DEPTH;
	ctx->modelview_max_stack_depth = MODELVIEW_MAX_STACK_DEPTH;
	ctx->matrix_mode = FTG_MODELVIEW;
	ctx->depth_func = FTG_LESS;
	ctx->depth_writemask = FTG_TRUE;
	ctx->blend_src_rgb = FTG_ONE;
	ctx->blend_src_alpha = FTG_ONE;
	ctx->blend_dst_rgb = FTG_ZERO;
	ctx->blend_dst_alpha = FTG_ZERO;
	ctx->blend_equation_rgb = FTG_FUNC_ADD;
	ctx->blend_equation_alpha = FTG_FUNC_ADD;
	ctx->fog_mode = FTG_EXP;
	ctx->fog_density = 1;
	ctx->fog_start = 0;
	ctx->fog_end = 1;
	ctx->fog_index = 0;
	ctx->vertex_array_size = 4;
	ctx->vertex_array_type = FTG_FLOAT;
	ctx->vertex_array_pointer = NULL;
	ctx->color_array_size = 4;
	ctx->color_array_type = FTG_FLOAT;
	if (!(ctx->textures = malloc(sizeof(*ctx->textures) * 2)))
	{
		ft_putstr("Malloc failed\n");
		raise(SIGABRT);
	}
	ft_memset(ctx->textures, 0, sizeof(*ctx->textures) * 2);
	ctx->textures_capacity = 0;
	ctx->texture_coord_array_size = 4;
	ctx->texture_coord_array_type = FTG_FLOAT;
	init_2(ctx);
}
