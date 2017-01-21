/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_triangle_truncate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:16:59 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 14:21:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

t_ftg_boolean	ftg_rast_triangle_truncate(t_vec4 *p1, t_vec4 *p2, t_vec4 *p3)
{
	if (p1->x < 0 && p2->x < 0 && p3->x < 0)
		return (FTG_TRUE);
	else if (p1->y < 0 && p2->y < 0 && p3->y < 0)
		return (FTG_TRUE);
	else if (p1->x >= g_ctx->width && p2->x >= g_ctx->width && p3->x >= g_ctx->width)
		return (FTG_TRUE);
	else if (p1->y >= g_ctx->height && p2->y >= g_ctx->height && p3->y >= g_ctx->height)
		return (FTG_TRUE);
	return (FTG_FALSE);
}
