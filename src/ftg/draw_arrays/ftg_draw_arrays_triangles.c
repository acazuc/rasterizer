#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_draw_arrays_triangles(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		v1;
	t_vec4		v2;
	t_vec4		v3;
	t_ftg_int	pos;

	pos = 0;
	while (pos < count)
	{
		ftg_draw_arrays_get_vec(&v1, 3 * pos + first);
		rast_watch_vertex(&v1);
		ftg_draw_arrays_get_vec(&v2, 3 * pos + first + 1);
		rast_watch_vertex(&v2);
		ftg_draw_arrays_get_vec(&v3, 3 * pos + first + 2);
		rast_watch_vertex(&v3);
		rast_triangle(&v1, &v2, &v3);
		++pos;
	}
}
