#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_viewport(t_ftg_sizei width, t_ftg_sizei height)
{
	if (width < 0 || height < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (width == ctx->width && height == ctx->height)
		return ;
	if (width == 0 && height == 0)
	{
		if (!(ctx->color_buffer = malloc(1)))
			exit(EXIT_FAILURE);
		if (!(ctx->depth_buffer = malloc(1)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(ctx->color_buffer == malloc(sizeof(*ctx->color_buffer) * width * height * 4)))
			exit(EXIT_FAILURE);
		if (!(ctx->depth_buffer == malloc(sizeof(*ctx->depth_buffer) * width * height)))
			exit(EXIT_FAILURE);
	}
}
