#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	alloc_new(void)
{
	t_ftg_texture	**new;
	t_ftg_uint	i;

	if (!(new = malloc(sizeof(*new) * (g_ctx->textures_capacity + 20))))
	{
		ft_putstr("malloc() failed");
		raise(SIGABRT);
	}
	i = 0;
	while (i < g_ctx->textures_capacity)
	{
		new[i] = g_ctx->textures[i];
		++i;
	}
	while (i < g_ctx->textures_capacity + 20)
	{
		new[i] = NULL;
		++i;
	}
	free(g_ctx->textures);
	g_ctx->textures = new;
	g_ctx->textures_capacity += 20;
}

static void	get_tex(t_ftg_uint *tex, t_ftg_uint *index)
{
	while (*index < g_ctx->textures_capacity && g_ctx->textures[*index])
		++(*index);
	if (*index == g_ctx->textures_capacity)
		alloc_new();
	if (!(g_ctx->textures[*index] = malloc(sizeof(**g_ctx->textures))))
	{
		ft_putstr("malloc() failed");
		raise(SIGABRT);
	}
	ft_memset(g_ctx->textures[*index], 0, sizeof(**g_ctx->textures));
	*tex = *index;
}

void		ftg_gen_textures(t_ftg_sizei n, t_ftg_uint *textures)
{
	t_ftg_uint	index;
	int		i;

	if (n < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	i = 1;
	while (i < n)
	{
		get_tex(&textures[i], &index);
		++i;
	}
}
