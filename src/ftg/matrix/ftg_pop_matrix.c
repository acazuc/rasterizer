/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_pop_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:22:20 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:24:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_pop_matrix(void)
{
	if (g_ctx->matrix_mode == FTG_MODELVIEW)
	{
		if (g_ctx->modelview_stack_depth <= 0)
		{
			g_ctx->errno = FTG_STACK_UNDERFLOW;
			return ;
		}
		g_ctx->modelview_stack_depth--;
	}
	else if (g_ctx->matrix_mode == FTG_PROJECTION)
	{
		if (g_ctx->projection_stack_depth <= 0)
		{
			g_ctx->errno = FTG_STACK_UNDERFLOW;
			return ;
		}
		g_ctx->projection_stack_depth--;
	}
	else
	{
		ft_putstr("Invalid matrix mode\n");
		raise(SIGABRT);
	}
}
