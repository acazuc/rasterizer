#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_clear(t_ftg_bitmask mask)
{
	if (mask & FTG_COLOR_BUFFER_BIT)
	{
		mask &= ~FTG_COLOR_BUFFER_BIT;
		ft_memset(ctx->color_buffer, 0, sizeof(*ctx->color_buffer) * ctx->width * ctx->height);
	}
	if (mask & FTG_DEPTH_BUFFER_BIT)
	{
		mask &= ~FTG_DEPTH_BUFFER_BIT;
		ft_memset(ctx->depth_buffer, 0, sizeof(*ctx->depth_buffer) * ctx->width * ctx->height);
	}
	if (mask)
		ctx->errno = FTG_INVALID_VALUE;
}
