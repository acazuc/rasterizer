#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_load_matrixd(const t_ftg_double *m)
{
	t_ftg_double	*dst;

	if (ctx->matrix_mode == FTG_MODELVIEW)
	{
		dst = ctx->matrix_modelview.value;
	}
	else if (ctx->matrix_mode == FTG_PROJECTION)
	{
		dst = ctx->matrix_projection.value;
	}
	else
	{
		ft_putendl_fd("Invalid matrix type", 2);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(dst, m, sizeof(*dst) * 16);
}

void	ftg_load_matrixf(const t_ftg_float *m)
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
