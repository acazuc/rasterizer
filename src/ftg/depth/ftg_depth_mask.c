/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_depth_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:54 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:30:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_depth_mask(t_ftg_boolean flag)
{
	if (flag == FTG_FALSE)
	{
		ctx->depth_writemask = FTG_FALSE;
	}
	else
	{
		ctx->depth_writemask = FTG_TRUE;
	}
}
