#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_load_matrixd(const t_ftg_double *m)
{
	t_ftg_double	*dst;

	dst = NULL;
	printf("%d\n", ctx->matrix_mode);
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
		ft_putstr_fd("Invalid matrix type\n", 2);
		raise(SIGABRT);
	}
	ft_memcpy(dst, m, sizeof(*m) * 16);
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
