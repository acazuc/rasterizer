#include "libftg.h"

t_ftg_ctx	*ctx;

static void	_allocate_buffers()
{
	if (!(ctx->color_buffer = malloc(sizeof(*ctx->color_buffer) * ctx->height * ctx->width * 4)))
	{
		ft_putstr("Failed to malloc color buffer 1st dimension\n");
		raise(SIGABRT);
	}
	if (!(ctx->depth_buffer = malloc(sizeof(*ctx->depth_buffer) * ctx->height * ctx->width)))
	{
		ft_putstr("Failed to malloc color buffer 1st dimension\n");
		raise(SIGABRT);
	}
}

static void	_free_buffers()
{
	free(ctx->color_buffer);
	free(ctx->depth_buffer);
}

void		ftg_viewport(t_ftg_sizei width, t_ftg_sizei height)
{
	if (width < 0 || height < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (width == ctx->width && height == ctx->height)
		return ;
	_free_buffers();
	ctx->width = width;
	ctx->height = height;
	if (width == 0 && height == 0)
	{
		if (!(ctx->color_buffer = malloc(1)))
			exit(EXIT_FAILURE);
		if (!(ctx->depth_buffer = malloc(1)))
			exit(EXIT_FAILURE);
	}
	else
	{
		_allocate_buffers();
	}
}
