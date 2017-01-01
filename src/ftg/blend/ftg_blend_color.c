#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_blend_color(t_ftg_clampf red, t_ftg_clampf green, t_ftg_clampf blue,t_ftg_clampf alpha)
{
	red = ftg_maxf(0, ftg_minf(1, red));
	green = ftg_maxf(0, ftg_minf(1, green));
	blue = ftg_maxf(0, ftg_minf(1, blue));
	alpha = ftg_maxf(0, ftg_minf(1, alpha));
	ctx->blend_color[0] = red;
	ctx->blend_color[1] = green;
	ctx->blend_color[2] = blue;
	ctx->blend_color[3] = alpha;
}
