#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_vertex(t_vec4 *vec)
{
	t_vec4	tmp;

	ft_memcpy(&tmp, vec, sizeof(tmp));
	tmp.x = round(tmp.x);
	tmp.y = round(tmp.y);
	rast_pixel_put(&tmp);
}
