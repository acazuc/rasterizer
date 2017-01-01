#include "libftg.h"

t_ftg_ctx	*ctx;

double	rast_depthbuffer_get(int x, int y)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height)
		return (0);
	return (ctx->depth_buffer[y * ctx->width + x]);
}
