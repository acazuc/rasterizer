#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_boolean	ftg_get(t_ftg_enum pname, void **data, t_ftg_enum *format, t_ftg_uint *length)
{
	if (pname == FTG_MATRIX_MODE)
	{
		*data = &ctx->matrix_mode;
		*format = FTG_INT;
		*length = 1;
	}
	else if (pname == FTG_MODELVIEW_MATRIX)
	{
		*data = ctx->matrix_modelview.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else if (pname == FTG_PROJECTION_MATRIX)
	{
		*data = ctx->matrix_projection.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else if (pname == FTG_DEPTH_RANGE)
	{
		*data = ctx->depth_range;
		*format = FTG_CLAMPD;
		*length = 2;
	}
	else if (pname == FTG_DEPTH_FUNC)
	{
		*data = &ctx->depth_func;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_DEPTH_TEST)
	{
		*data = &ctx->depth_test;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_DEPTH_WRITEMASK)
	{
		*data = &ctx->depth_writemask;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_BLEND_SRC_RGB)
	{
		*data = &ctx->blend_src_rgb;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_SRC_ALPHA)
	{
		*data = &ctx->blend_src_alpha;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_DST_RGB)
	{
		*data = &ctx->blend_dst_rgb;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_DST_ALPHA)
	{
		*data = &ctx->blend_dst_alpha;
		*format = FTG_ENUM;
		*length = 1;
	}
	else
	{
		ctx->errno = FTG_INVALID_ENUM;
		return (FTG_FALSE);
	}
	return (FTG_TRUE);
}
