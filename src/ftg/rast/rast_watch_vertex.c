#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_watch_vertex(t_vec4 *vec)
{
	mat4_transform_vec4(&ctx->matrix_modelview, vec);
	mat4_transform_vec4(&ctx->matrix_projection, vec);
	if (vec->z != 0)
	{
		vec->x /= vec->z;
		vec->y /= vec->z;
	}
	vec->x = ctx->width / 2 + vec->x * ctx->width / 2;
	vec->y = ctx->height / 2 + vec->y * ctx->height / 2;
}
