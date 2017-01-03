/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:09:45 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:10:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

static void	allocate_buffers(void)
{
	if (!(ctx->color_buffer = malloc(sizeof(*ctx->color_buffer)
					* ctx->height * ctx->width * 4)))
	{
		ft_putstr_fd("Failed to malloc color buffer\n", 2);
		raise(SIGABRT);
	}
	if (!(ctx->depth_buffer = malloc(sizeof(*ctx->depth_buffer)
					* ctx->height * ctx->width)))
	{
		ft_putstr_fd("Failed to malloc depth buffer\n", 2);
		raise(SIGABRT);
	}
}

static void	free_buffers(void)
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
	free_buffers();
	ctx->width = width;
	ctx->height = height;
	if (width == 0 && height == 0)
	{
		if (!(ctx->color_buffer = malloc(1)))
		{
			ft_putstr_fd("Failed to malloc color buffer\n", 2);
			raise(SIGABRT);
		}
		if (!(ctx->depth_buffer = malloc(1)))
		{
			ft_putstr_fd("Failed to malloc depth buffer\n", 2);
			raise(SIGABRT);
		}
	}
	else
	{
		allocate_buffers();
	}
}
