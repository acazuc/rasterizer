/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_is_enabled.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:12:26 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:12:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_boolean	ftg_is_enabled(t_ftg_enum cap)
{
	if (cap == FTG_DEPTH_TEST)
		return (ctx->depth_test);
	else if (cap == FTG_BLEND)
		return (ctx->blend);
	else if (cap == FTG_FOG)
		return (ctx->fog);
	ctx->errno = FTG_INVALID_ENUM;
	return (0);
}
