/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_color_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:12:45 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:28:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_color_pointer(t_ftg_int size, t_ftg_enum type, t_ftg_sizei stride
		, const t_ftg_void *pointer)
{
	if (size != 3 && size != 4)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (type != FTG_BYTE && type != FTG_UNSIGNED_BYTE
		&& type != FTG_SHORT && type != FTG_UNSIGNED_SHORT
		&& type != FTG_INT && type != FTG_UNSIGNED_INT
		&& type != FTG_FLOAT && type != FTG_DOUBLE)
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (stride < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	g_ctx->color_array_size = size;
	g_ctx->color_array_type = type;
	g_ctx->color_array_stride = stride;
	g_ctx->color_array_pointer = pointer;
}
