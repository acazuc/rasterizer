/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_disable_client_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:23 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:33:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_disable_client_state(t_ftg_enum cap)
{
	if (cap == FTG_COLOR_ARRAY)
		g_ctx->color_array = FTG_FALSE;
	else if (cap == FTG_VERTEX_ARRAY)
		g_ctx->vertex_array = FTG_FALSE;
	else
		g_ctx->errno = FTG_INVALID_ENUM;
}
