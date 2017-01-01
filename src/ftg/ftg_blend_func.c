#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_blend_func(t_ftg_enum s_factor, t_ftg_enum d_factor)
{
	ftg_blend_func_separate(s_factor, d_factor, s_factor, d_factor);
}
