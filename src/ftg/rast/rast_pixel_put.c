#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_pixel_put(t_vec4 *vec)
{
	double	current_z;

	if (vec->x < 0 || vec->x >= ctx->width || vec->y < 0 || vec->y >= ctx->height
			|| vec->z < 0)
		return ;
	current_z = rast_depthbuffer_get(vec->x, vec->y);
	if (current_z && vec->z >= current_z)
		return ;
	rast_pixel_set(vec->x, vec->y, &vec->color);
	rast_depthbuffer_set(vec->x, vec->y, vec->z);
}
