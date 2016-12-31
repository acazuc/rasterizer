#include "libftg.h"

void	ftg_ctx_init(t_ftg_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
	mat4_init_identity(ctx->matrix_view);
	mat4_init_identity(ctx->matrix_model);
}
