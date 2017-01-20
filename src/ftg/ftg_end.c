#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_end()
{
	if (g_ctx->fog)
		ftg_fog_place();
}
