#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_blend_equation(t_ftg_enum mode)
{
	ftg_blend_equation_separate(mode, mode);
}
