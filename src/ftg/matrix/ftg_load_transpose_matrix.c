/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_load_transpose_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:50:53 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:16:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_load_transpose_matrixd(const t_ftg_double *m)
{
	t_mat4	*dst;

	if (g_ctx->matrix_mode == FTG_MODELVIEW)
	{
		dst = &g_ctx->modelview_matrix[g_ctx->modelview_stack_depth];
	}
	else if (g_ctx->matrix_mode == FTG_PROJECTION)
	{
		dst = &g_ctx->projection_matrix[g_ctx->projection_stack_depth];
	}
	else
	{
		ft_putstr_fd("Invalid matrix type\n", 2);
		raise(SIGABRT);
		return ;
	}
	ft_memcpy(dst->value, m, sizeof(*m) * 16);
	mat4_reverse(dst);
}

void	ftg_load_transpose_matrixf(const t_ftg_float *m)
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
