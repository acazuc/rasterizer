#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_pixel_set_blend_equ_alpha(t_color *src, t_color *dst, float **org)
{
	if (g_ctx->blend_equation_alpha == FTG_FUNC_ADD)
		*org[3] = src->alpha + dst->alpha;
	else if (g_ctx->blend_equation_alpha == FTG_FUNC_SUBSTRACT)
		*org[3] = src->alpha - dst->alpha;
	else if (g_ctx->blend_equation_alpha == FTG_FUNC_REVERSE_SUBSTRACT)
		*org[3] = dst->alpha - src->alpha;
	else if (g_ctx->blend_equation_alpha == FTG_MIN)
		*org[3] = ftg_minf(src->alpha, dst->alpha);
	else if (g_ctx->blend_equation_alpha == FTG_MAX)
		*org[3] = ftg_maxf(src->alpha, dst->alpha);
}
