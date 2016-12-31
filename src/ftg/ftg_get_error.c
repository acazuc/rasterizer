#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_enum	ftg_get_error()
{
	t_ftg_enum	error;

	error = ctx->errno;
	ctx->errno = FTG_NO_ERROR;
	return (error);
}
