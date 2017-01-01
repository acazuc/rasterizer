#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_depthbuffer_set(int x, int y, double z)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height)
		return ;
	ctx->depth_buffer[y * ctx->width + x] = z;
}
