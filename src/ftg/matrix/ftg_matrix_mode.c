/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_matrix_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:50:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 18:50:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_matrix_mode(t_ftg_enum mode)
{
	if (mode == FTG_MODELVIEW || mode == FTG_PROJECTION)
	{
		ctx->matrix_mode = mode;
	}
	else
	{
		ctx->errno = FTG_INVALID_ENUM;
	}
}
