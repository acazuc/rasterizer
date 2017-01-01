#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_depth_func(t_ftg_enum func)
{
	if (func == FTG_NEVER || func == FTG_LESS || func == FTG_EQUAL || func == FTG_LEQUAL || func == FTG_GREATER || func == FTG_NOTEQUAL || func == FTG_GEQUAL || func == FTG_ALWAYS)
		ctx->depth_func = func;
	else
		ctx->errno = FTG_INVALID_ENUM;
}