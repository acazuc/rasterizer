#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_mult_transpose_matrixd(const t_ftg_double *m)
{
	t_mat4	cur_mat;
	t_mat4	new;

	ft_memcpy(new.value, m, sizeof(*m) * 16);
	mat4_reverse(&new);
	ftg_get_doublev(ctx->matrix_mode, cur_mat.value);
	mat4_mult(&cur_mat, &cur_mat, &new);
	ftg_load_matrixd(cur_mat.value);
}

void	ftg_mult_transpose_matrixf(const t_ftg_float *m)
{
	double	new[16];
	int	i;

	i = 0;
	while (i < 16)
	{
		new[i] = m[i];
		++i;
	}
	ftg_mult_transpose_matrixd(new);
}
