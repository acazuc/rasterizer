#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_draw_arrays_line_strip(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		v1;
	t_vec4		v2;
	t_ftg_int	pos;

	pos = 0;
	ftg_draw_arrays_get_vec(&v1, 2 * pos + first);
	rast_watch_vertex(&v1);
	while (pos < count - 1)
	{
		ftg_draw_arrays_get_vec(&v2, 2 * pos + first + 1);
		rast_watch_vertex(&v2);
		rast_line(&v1, &v2);
		v1 = v2;
		++pos;
	}
}
