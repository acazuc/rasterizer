#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_load_transpose_matrixd(const t_ftg_double *m)
{
	t_mat4	*dst;

	if (ctx->matrix_mode == FTG_MODELVIEW)
	{
		dst = &ctx->matrix_modelview;
	}
	else if (ctx->matrix_mode == FTG_PROJECTION)
	{
		dst = &ctx->matrix_projection;
	}
	else
	{
		ft_putendl_fd("Invalid matrix type", 2);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(dst->value, m, sizeof(*m) * 16);
	mat4_reverse(dst);

}

void	ftg_load_transpose_matrixf(const t_ftg_float *m)
{
	double	new[16];
	int	i;

	i = 0;
	while (i < 16)
	{
		new[i] = m[i];
		++i;
	}
	ftg_load_matrixd(new);
}
