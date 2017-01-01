#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	_test(double test, double cur)
{
	if (ctx->depth_func == FTG_NEVER)
		return (FTG_FALSE);
	else if (ctx->depth_func == FTG_LESS)
		return (test < cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_EQUAL)
		return (test == cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_LEQUAL)
		return (test <= cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_GREATER)
		return (test > cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_NOTEQUAL)
		return (test != cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_GEQUAL)
		return (test >= cur ? FTG_TRUE : FTG_FALSE);
	else if (ctx->depth_func == FTG_ALWAYS)
		return (FTG_TRUE);
	return (FTG_TRUE);
}

void	rast_pixel_put(t_vec4 *vec)
{
	double	current_z;

	if (vec->x < 0 || vec->x >= ctx->width || vec->y < 0 || vec->y >= ctx->height
			|| vec->z < 0)
		return ;
	current_z = rast_depthbuffer_get(vec->x, vec->y);
	if (current_z && !_test(vec->z, current_z))
		return ;
	rast_pixel_set(vec->x, vec->y, &vec->color);
	rast_depthbuffer_set(vec->x, vec->y, vec->z);
}
