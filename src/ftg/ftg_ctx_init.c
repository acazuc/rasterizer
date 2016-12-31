#include "libftg.h"

void	ftg_ctx_init(t_ftg_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
	mat4_init_identity(&ctx->matrix_projection);
	mat4_init_identity(&ctx->matrix_modelview);
	ctx->matrix_mode = FTG_MODELVIEW;
}
