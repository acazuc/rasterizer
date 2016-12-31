#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_boolean	ftg_get(t_ftg_enum pname, void **data, t_ftg_enum *format, t_ftg_uint *length)
{
	if (pname == FTG_MATRIX_MODE)
	{
		*data = &ctx->matrix_mode;
		*format = FTG_INT;
		*length = 1;
	}
	else if (pname == FTG_MODELVIEW_MATRIX)
	{
		*data = ctx->matrix_modelview.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else if (pname == FTG_PROJECTION_MATRIX)
	{
		*data = ctx->matrix_projection.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else
	{
		ctx->errno = FTG_INVALID_ENUM;
		return (FTG_FALSE);
	}
	return (FTG_TRUE);
}
