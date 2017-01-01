#include "libftg.h"

t_ftg_ctx	*ctx;

static void	_clear_colors()
{
	int	i;

	i = 0;
	while (i < ctx->width * ctx->height)
	{
		ctx->color_buffer[i * 4 + 0] = ctx->clear_color[0];
		ctx->color_buffer[i * 4 + 1] = ctx->clear_color[1];
		ctx->color_buffer[i * 4 + 2] = ctx->clear_color[2];
		ctx->color_buffer[i * 4 + 3] = ctx->clear_color[3];
		++i;
	}
}

static void	_clear_depth()
{
	int	i;

	i = 0;
	while (i < ctx->width * ctx->height)
	{
		ctx->depth_buffer[i] = 0;
		++i;
	}
}

void	ftg_clear(t_ftg_bitmask mask)
{
	if (mask & FTG_COLOR_BUFFER_BIT)
	{
		mask &= ~FTG_COLOR_BUFFER_BIT;
		_clear_colors();
	}
	if (mask & FTG_DEPTH_BUFFER_BIT)
	{
		mask &= ~FTG_DEPTH_BUFFER_BIT;
		_clear_depth();
	}
	if (mask)
		ctx->errno = FTG_INVALID_VALUE;
}
