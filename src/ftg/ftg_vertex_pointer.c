/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_vertex_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:21 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:41:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_vertex_pointer(t_ftg_int size, t_ftg_enum type, t_ftg_sizei stride
		, const t_ftg_void *pointer)
{
	if (size != 2 && size != 3 && size != 4)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (type != FTG_SHORT && type != FTG_INT && type != FTG_FLOAT
			&& type != FTG_DOUBLE)
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (stride < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	g_ctx->vertex_array_size = size;
	g_ctx->vertex_array_type = type;
	g_ctx->vertex_array_stride = stride;
	g_ctx->vertex_array_pointer = pointer;
}
