/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_is_enabled.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:12:26 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:41:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

t_ftg_boolean	ftg_is_enabled(t_ftg_enum cap)
{
	if (cap == FTG_DEPTH_TEST)
		return (g_ctx->depth_test);
	else if (cap == FTG_BLEND)
		return (g_ctx->blend);
	else if (cap == FTG_FOG)
		return (g_ctx->fog);
	g_ctx->errno = FTG_INVALID_ENUM;
	return (0);
}
