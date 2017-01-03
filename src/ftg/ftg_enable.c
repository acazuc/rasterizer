/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_enable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:34 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:26:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_enable(t_ftg_enum cap)
{
	if (cap == FTG_DEPTH_TEST)
		g_ctx->depth_test = FTG_TRUE;
	else if (cap == FTG_BLEND)
		g_ctx->blend = FTG_TRUE;
	else if (cap == FTG_FOG)
		g_ctx->fog = FTG_TRUE;
	else
		g_ctx->errno = FTG_INVALID_ENUM;
}
