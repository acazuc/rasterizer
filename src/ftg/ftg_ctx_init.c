#include "libftg.h"

void	ftg_ctx_init(t_ftg_ctx *ctx)
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
}
