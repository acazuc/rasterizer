#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_enable_client_state(t_ftg_enum cap)
{
	if (cap == FTG_COLOR_ARRAY)
		ctx->color_array = FTG_TRUE;
	else if (cap == FTG_VERTEX_ARRAY)
		ctx->vertex_array = FTG_TRUE;
	else
		ctx->errno = FTG_INVALID_ENUM;
}
