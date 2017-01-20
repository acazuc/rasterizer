#include "libftg.h"

t_ftg_ctx	*g_ctx;

t_ftg_boolean	ftg_is_texture(t_ftg_uint texture)
{
	if (texture <= 0 || texture >= g_ctx->textures_capacity)
		return (FTG_FALSE);
	if (!g_ctx->textures[texture])
		return (FTG_FALSE);
	return (FTG_TRUE);
}
