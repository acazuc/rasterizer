/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_get_pointerv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:14:23 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 13:21:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_get_pointerv(t_ftg_enum pname, t_ftg_void **params)
{
	if (pname == FTG_COLOR_ARRAY_POINTER)
		*params = (t_ftg_void*)g_ctx->color_array_pointer;
	else if (pname == FTG_TEXTURE_COORD_ARRAY_POINTER)
		*params = (t_ftg_void*)g_ctx->texture_coord_array_pointer;
	else if (pname == FTG_VERTEX_ARRAY_POINTER)
		*params = (t_ftg_void*)g_ctx->vertex_array_pointer;
	else
		g_ctx->errno = FTG_INVALID_ENUM;
}
