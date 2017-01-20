#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	do_2(t_color *src, t_color *dst, float **org)
{
	if (g_ctx->blend_equation_rgb == FTG_MIN)
	{
		*org[0] = ftg_minf(src->red, dst->red);
		*org[1] = ftg_minf(src->green, dst->green);
		*org[2] = ftg_minf(src->blue, dst->blue);
	}
	else if (g_ctx->blend_equation_rgb == FTG_MAX)
	{
		*org[0] = ftg_maxf(src->red, dst->red);
		*org[1] = ftg_maxf(src->green, dst->green);
		*org[2] = ftg_maxf(src->blue, dst->blue);
	}
}

void	ftg_rast_pixel_set_blend_equ_rgb(t_color *src, t_color *dst, float **org)
{
	if (g_ctx->blend_equation_rgb == FTG_FUNC_ADD)
	{
		*org[0] = src->red + dst->red;
		*org[1] = src->green + dst->green;
		*org[2] = src->blue + dst->blue;
	}
	else if (g_ctx->blend_equation_rgb == FTG_FUNC_SUBSTRACT)
	{
		*org[0] = src->red - dst->red;
		*org[1] = src->green - dst->green;
		*org[2] = src->blue - dst->blue;
	}
	else if (g_ctx->blend_equation_rgb == FTG_FUNC_REVERSE_SUBSTRACT)
	{
		*org[0] = dst->red - src->red;
		*org[1] = dst->green - src->green;
		*org[2] = dst->blue - src->blue;
	}
	else
		do_2(src, dst, org);
}
