#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_depth_mask(t_ftg_boolean flag)
{
	if (flag == FTG_FALSE)
	{
		ctx->depth_writemask = FTG_FALSE;
	}
	else
	{
		ctx->depth_writemask = FTG_TRUE;
	}
}
