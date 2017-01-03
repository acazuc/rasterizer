/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_enable_client_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:37 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:13:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_enable_client_state(t_ftg_enum cap)
{
	if (cap == FTG_COLOR_ARRAY)
		ctx->color_array = FTG_TRUE;
	else if (cap == FTG_VERTEX_ARRAY)
		ctx->vertex_array = FTG_TRUE;
	else
		ctx->errno = FTG_INVALID_ENUM;
}
