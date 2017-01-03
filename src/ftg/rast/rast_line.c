#include "libftg.h"

t_ftg_ctx	*ctx;

void			rast_line(t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	dif;

	if (rast_line_truncate(v1, v2, &dif))
		return ;
	if (fabs(dif.x) > fabs(dif.y))
	{
		if (dif.x < 0)
			rast_line_draw_left(v1, &dif);
		else
			rast_line_draw_right(v1, &dif);
	}
	else
	{
		if (dif.y < 0)
			rast_line_draw_bottom(v1, &dif);
		else
			rast_line_draw_top(v1, &dif);
	}
}
