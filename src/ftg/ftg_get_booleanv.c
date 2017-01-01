#include "libftg.h"

t_ftg_ctx	*ctx;

static void	ftg_get_booleanv_convert(t_ftg_boolean *params, void *data, t_ftg_enum format, t_ftg_uint length)
{
	t_ftg_uint	i;

	i = 0;
	while (i < length)
	{
		if (format == FTG_BYTE)
			params[i] = ((t_ftg_byte*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_UNSIGNED_BYTE)
			params[i] = ((t_ftg_ubyte*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_SHORT)
			params[i] = ((t_ftg_short*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_UNSIGNED_SHORT)
			params[i] = ((t_ftg_ushort*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_INT)
			params[i] = ((t_ftg_int*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_UNSIGNED_INT)
			params[i] = ((t_ftg_uint*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_FLOAT)
			params[i] = ((t_ftg_float*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_CLAMPF)
			params[i] = ((t_ftg_clampf*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_DOUBLE)
			params[i] = ((t_ftg_double*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		else if (format == FTG_CLAMPD)
			params[i] = ((t_ftg_clampd*)data)[i] == 0 ? FTG_FALSE : FTG_TRUE;
		++i;
	}
}

void		ftg_get_booleanv(t_ftg_enum pname, t_ftg_boolean *params)
{
	void		*data;
	t_ftg_enum	format;
	t_ftg_uint	length;

	if (!ftg_get(pname, &data, &format, &length))
		return ;
	if (format == FTG_BOOLEAN)
	{
		ft_memcpy(params, data, length * sizeof(*params));
		return ;
	}
	ftg_get_booleanv_convert(params, data, format, length);
}
