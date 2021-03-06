/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_depth_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:46 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:35:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_depth_range(t_ftg_clampd near_val, t_ftg_clampd far_val)
{
	g_ctx->depth_range[0] = near_val;
	g_ctx->depth_range[1] = far_val;
}
