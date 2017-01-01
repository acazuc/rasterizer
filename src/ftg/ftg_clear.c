#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_clear(t_ftg_bitmask mask)
{
	int	i;

	if (mask & FTG_COLOR_BUFFER_BIT)
	{
		mask &= ~FTG_COLOR_BUFFER_BIT;
		ft_memset(ctx->color_buffer, 0, sizeof(*ctx->color_buffer) * ctx->width * ctx->height * 4);
	}
	if (mask & FTG_DEPTH_BUFFER_BIT)
	{
		mask &= ~FTG_DEPTH_BUFFER_BIT;
		i = 0;
		while (i < ctx->width * ctx->height)
		{
			ctx->depth_buffer[i] = 0;
			++i;
		}
	}
	if (mask)
		ctx->errno = FTG_INVALID_VALUE;
}
