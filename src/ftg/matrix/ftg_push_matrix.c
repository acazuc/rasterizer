/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_push_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:54:37 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:23:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_push_matrix(void)
{
	if (g_ctx->matrix_mode == FTG_MODELVIEW)
	{
		if (g_ctx->modelview_stack_depth >= g_ctx->modelview_max_stack_depth - 1)
		{
			g_ctx->errno = FTG_STACK_OVERFLOW;
			return ;
		}
		ft_memcpy(&g_ctx->modelview_matrix[g_ctx->modelview_stack_depth + 1]
				, &g_ctx->modelview_matrix[g_ctx->modelview_stack_depth]
				, sizeof(*g_ctx->modelview_matrix));
		g_ctx->modelview_stack_depth++;
	}
	else if (g_ctx->matrix_mode == FTG_PROJECTION)
	{
		if (g_ctx->projection_stack_depth >= g_ctx->projection_max_stack_depth - 1)
		{
			g_ctx->errno = FTG_STACK_OVERFLOW;
			return ;
		}
		ft_memcpy(&g_ctx->projection_matrix[g_ctx->projection_stack_depth + 1]
				, &g_ctx->projection_matrix[g_ctx->projection_stack_depth]
				, sizeof(*g_ctx->projection_matrix));
		g_ctx->projection_stack_depth++;
	}
	else
	{
		ft_putstr("Invalid matrix mode\n");
		raise(SIGABRT);
	}
}
