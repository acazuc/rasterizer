#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_watch_vertex(t_vec4 *vec)
{
	mat4_transform_vec4(&ctx->matrix_modelview, vec);
	mat4_transform_vec4(&ctx->matrix_projection, vec);
	if (vec->w != 0)
	{
		vec->x /= vec->w;
		vec->y /= vec->w;
		vec->z /= vec->w;
	}
	vec->x = round(ctx->width / 2 + vec->x * ctx->width / 2);
	vec->y = round(ctx->height / 2 + vec->y * ctx->height / 2);
}
