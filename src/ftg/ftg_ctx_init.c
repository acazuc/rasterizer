/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_ctx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:49 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:12:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx = NULL;

static void	init_2(t_ftg_ctx *ctx)
{
	ctx->color_array_stride = 0;
	ctx->color_array_pointer = NULL;
}

void		ftg_ctx_init(t_ftg_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
	mat4_init_identity(&ctx->matrix_projection);
	mat4_init_identity(&ctx->matrix_modelview);
	ftg_viewport(0, 0);
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
	ctx->vertex_array_stride = 0;
	ctx->vertex_array_pointer = NULL;
	ctx->color_array_size = 4;
	ctx->color_array_type = FTG_FLOAT;
	init_2(ctx);
}
