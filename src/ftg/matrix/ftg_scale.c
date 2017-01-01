#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_scaled(t_ftg_double x, t_ftg_double y, t_ftg_double z)
{
	t_mat4	scale;

	mat4_init_scale(&scale, x, y, z);
	ftg_mult_matrixd(scale.value);
}

void	ftg_scalef(t_ftg_float x, t_ftg_float y, t_ftg_float z)
{
	ftg_scaled(x, y, z);
}
