/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_enable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:34 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:13:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_enable(t_ftg_enum cap)
{
	if (cap == FTG_DEPTH_TEST)
		ctx->depth_test = FTG_TRUE;
	else if (cap == FTG_BLEND)
		ctx->blend = FTG_TRUE;
	else if (cap == FTG_FOG)
		ctx->fog = FTG_TRUE;
	else
		ctx->errno = FTG_INVALID_ENUM;
}
