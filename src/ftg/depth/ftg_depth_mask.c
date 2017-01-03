/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_depth_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:54 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:35:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_depth_mask(t_ftg_boolean flag)
{
	if (!flag)
	{
		g_ctx->depth_writemask = FTG_FALSE;
	}
	else
	{
		g_ctx->depth_writemask = FTG_TRUE;
	}
}
