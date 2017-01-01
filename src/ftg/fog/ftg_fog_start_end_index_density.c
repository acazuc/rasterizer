#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_double	_convert_to_double(void *data, t_ftg_enum type)
{
	if (type == FTG_FLOAT)
	{
		return (((t_ftg_float*)data)[0]);
	}
	else if (type == FTG_INT)
	{
		return (((t_ftg_int*)data)[0]);
	}
	return (0);
}

void	ftg_fog_start(void *data, t_ftg_enum type)
{
	ctx->fog_start = _convert_to_double(data, type);
}

void	ftg_fog_end(void *data, t_ftg_enum type)
{
	ctx->fog_end = _convert_to_double(data, type);
}

void	ftg_fog_index(void *data, t_ftg_enum type)
{
	ctx->fog_index = _convert_to_double(data, type);
}

void	ftg_fog_density(void *data, t_ftg_enum type)
{
	double	density;

	density = _convert_to_double(data, type);
	if (density < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	ctx->fog_density = density;
}
