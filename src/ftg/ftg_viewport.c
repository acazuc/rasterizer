/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:09:45 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:34:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	allocate_buffers(void)
{
	if (!(g_ctx->color_buffer = malloc(sizeof(*g_ctx->color_buffer)
					* g_ctx->height * g_ctx->width * 4)))
	{
		ft_putstr_fd("Failed to malloc color buffer\n", 2);
		raise(SIGABRT);
	}
	if (!(g_ctx->depth_buffer = malloc(sizeof(*g_ctx->depth_buffer)
					* g_ctx->height * g_ctx->width)))
	{
		ft_putstr_fd("Failed to malloc depth buffer\n", 2);
		raise(SIGABRT);
	}
}

static void	free_buffers(void)
{
	free(g_ctx->color_buffer);
	free(g_ctx->depth_buffer);
}

void		ftg_viewport(t_ftg_sizei width, t_ftg_sizei height)
{
	if (width < 0 || height < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (width == g_ctx->width && height == g_ctx->height)
		return ;
	free_buffers();
	g_ctx->width = width;
	g_ctx->height = height;
	if (width == 0 && height == 0)
	{
		if (!(g_ctx->color_buffer = malloc(1)))
		{
			ft_putstr_fd("Failed to malloc color buffer\n", 2);
			raise(SIGABRT);
		}
		if (!(g_ctx->depth_buffer = malloc(1)))
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
