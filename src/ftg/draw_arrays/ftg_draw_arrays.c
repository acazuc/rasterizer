#include "libftg.h"

t_ftg_ctx	*ctx;

static void	_draw_case(t_ftg_enum mode, t_ftg_int first, t_ftg_sizei count)
{
	if (mode == FTG_POINTS)
		ftg_draw_arrays_points(first, count);
	else if (mode == FTG_LINE_STRIP)
		ftg_draw_arrays_line_strip(first, count);
	else if (mode == FTG_LINES)
		ftg_draw_arrays_lines(first, count);
	else if (mode == FTG_TRIANGLES)
		ftg_draw_arrays_triangles(first, count);
	else if (mode == FTG_QUADS)
		ftg_draw_arrays_quads(first, count);
}

void		ftg_draw_arrays(t_ftg_enum mode, t_ftg_int first, t_ftg_sizei count)
{
	if (mode != FTG_POINTS && mode != FTG_LINE_STRIP && mode != FTG_LINE_LOOP && mode != FTG_LINES
		&& mode != FTG_TRIANGLE_STRIP && mode != FTG_TRIANGLE_FAN && mode != FTG_TRIANGLES
		&& mode != FTG_QUAD_STRIP && mode != FTG_QUADS && mode != FTG_POLYGONS)
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (count < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (!ctx->vertex_array)
		return ;
	if (!count)
		return;
	_draw_case(mode, first, count);
}
