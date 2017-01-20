#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	do_patch(t_ftg_enum target, t_ftg_uint texture)
{
	if (target == FTG_TEXTURE_2D)
	{
		if (g_ctx->textures[texture]->target != FTG_TEXTURE_2D)
		{
			g_ctx->errno = FTG_INVALID_OPERATION;
			return ;
		}
		g_ctx->texture_binding_2d = texture;
	}
	else if (target == FTG_TEXTURE_3D)
	{
		if (g_ctx->textures[texture]->target != FTG_TEXTURE_3D)
		{
			g_ctx->errno = FTG_INVALID_OPERATION;
			return ;
		}
		g_ctx->texture_binding_3d = texture;
	}
}

void	ftg_bind_texture(t_ftg_enum target, t_ftg_uint texture)
{
	t_ftg_texture	*texture;

	if (target != FTG_TEXTURE_1D && target != FTG_TEXTURE_2D && target != FTG_TEXTURE_3D)
	{
		g_ctx->errno = GL_INVALID_ENUM;
		return ;
	}
	if (!texture || texture < g_ctx->textures_capacity)
		return ;
	if (!g_ctx->textures[texture])
		return ;
	if (target == FTG_TEXTURE_1D)
	{
		if (g_ctx->textures[texture]->target != FTG_TEXTURE_1D)
		{
			g_ctx->errno = FTG_INVALID_OPERATION;
			return ;
		}
		g_ctx->texture_binding_1d = texture;
	}
	do_path(target, texture);
}
