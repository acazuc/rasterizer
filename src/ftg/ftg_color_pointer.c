#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_color_pointer(t_ftg_int size, t_ftg_enum type, t_ftg_sizei stride, const t_ftg_void *pointer)
{
	if (size != 3 && size != 4)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (type != FTG_BYTE && type != FTG_UNSIGNED_BYTE
		&& type != FTG_SHORT && type != FTG_UNSIGNED_SHORT
		&& type != FTG_INT && type != FTG_UNSIGNED_INT
		&& type != FTG_FLOAT && type != FTG_DOUBLE)
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (stride < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	ctx->color_array_size = size;
	ctx->color_array_type = type;
	ctx->color_array_stride = stride;
	ctx->color_array_pointer = pointer;
}
