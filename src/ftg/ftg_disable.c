/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_disable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:28 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:30:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_disable(t_ftg_enum cap)
{
	if (cap == FTG_DEPTH_TEST)
		g_ctx->depth_test = FTG_FALSE;
	else if (cap == FTG_BLEND)
		g_ctx->blend = FTG_FALSE;
	else if (cap == FTG_FOG)
		g_ctx->fog = FTG_FALSE;
	else
		g_ctx->errno = FTG_INVALID_ENUM;
}
