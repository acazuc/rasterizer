/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_load_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:50:24 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:15:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_load_matrixd(const t_ftg_double *m)
{
	t_ftg_double	*dst;

	if (g_ctx->matrix_mode == FTG_MODELVIEW)
	{
		dst = g_ctx->modelview_matrix[g_ctx->modelview_stack_depth].value;
	}
	else if (g_ctx->matrix_mode == FTG_PROJECTION)
	{
		dst = g_ctx->projection_matrix[g_ctx->projection_stack_depth].value;
	}
	else
	{
		ft_putstr_fd("Invalid matrix type\n", 2);
		raise(SIGABRT);
		return ;
	}
	ft_memcpy(dst, m, sizeof(*m) * 16);
}

void	ftg_load_matrixf(const t_ftg_float *m)
{
	double	new[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		new[i] = m[i];
		++i;
	}
	ftg_load_matrixd(new);
}
