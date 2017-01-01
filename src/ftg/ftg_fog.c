#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	_is_valid(t_ftg_enum pname)
{
	if (pname == FTG_FOG_MODE || pname == FTG_FOG_DENSITY
		|| pname == FTG_FOG_START || pname == FTG_FOG_END
		|| pname == FTG_FOG_INDEX || pname == FTG_FOG_COLOR)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

void	ftg_fogf(t_ftg_enum pname, t_ftg_float param)
{
	ftg_fogfv(pname, &param);
}

void	ftg_fogi(t_ftg_enum pname, t_ftg_int param)
{
	ftg_fogiv(pname, &param);
}

void	ftg_fogfv(t_ftg_enum pname, t_ftg_float *param)
{
	if (!_is_valid(pname))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	(void)pname;
	(void)param;
}

void	ftg_fogiv(t_ftg_enum pname, t_ftg_int *param)
{
	if (!_is_valid(pname))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	(void)pname;
	(void)param;
}
