#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	do_remove(t_ftg_sizei i)
{
	t_ftg_texture	*tex;

	tex = g_ctx->textures[i];
	if (tex->data)
		free(tex->data);
	free(tex);
	g_ctx->textures[i] = NULL;
}

void		ftg_delete_textures(t_ftg_sizei n, const t_ftg_uint *textures)
{
	t_ftg_sizei	i;

	if (n < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	i = 0;
	while (i < n)
	{
		if (textures[i] && textures[i] < g_ctx->textures_capacity)
		{
			if (textures[i] == g_ctx->texture_binding_1d)
				g_ctx->texture_binding_1d = 0;
			if (textures[i] == g_ctx->texture_binding_2d)
				g_ctx->texture_binding_2d = 0;
			if (textures[i] == g_ctx->texture_binding_3d)
				g_ctx->texture_binding_3d = 0;
			do_remove(textures[i]);
		}
		++i;
	}
}
