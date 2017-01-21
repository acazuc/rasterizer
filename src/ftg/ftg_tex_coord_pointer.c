/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_tex_coord_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:44:49 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 12:52:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_tex_coord_pointer(t_ftg_int size, t_ftg_enum type, t_ftg_sizei stride, const t_ftg_void *pointer)
{
	if (size < 1 || size > 4)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (type != FTG_SHORT && type != FTG_INT && type != FTG_FLOAT && type != FTG_DOUBLE)
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (stride < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	g_ctx->texture_coord_array_size = size;
	g_ctx->texture_coord_array_type = type;
	g_ctx->texture_coord_array_stride = stride;
	g_ctx->texture_coord_array_pointer = pointer;
}
