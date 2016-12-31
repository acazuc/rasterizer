#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_matrix_mode(t_ftg_enum mode)
{
	if (mode == FTG_MODELVIEW || mode == FTG_PROJECTION)
	{
		ctx->matrix_mode = mode;
	}
	else
	{
		ctx->errno = GL_INVALID_ENUM;
	}
}
