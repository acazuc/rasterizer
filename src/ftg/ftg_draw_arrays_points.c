#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_draw_arrays_points(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		vec;
	t_ftg_int	pos;

	pos = 0;
	while (pos < count)
	{
		ftg_draw_arrays_get_vec(&vec, pos + first);
		printf("1: x: %f, y: %f, z: %f, w: %f\n", vec.x, vec.y, vec.z, vec.w);
		rast_watch_vertex(&vec);
		printf("2: x: %f, y: %f, z: %f, w: %f\n", vec.x, vec.y, vec.z, vec.w);
		rast_vertex(&vec);
		++pos;
	}
}
