#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_depth_range(t_ftg_clampd near_val, t_ftg_clampd far_val)
{
	ctx->depth_range[0] = near_val;
	ctx->depth_range[1] = far_val;
}
