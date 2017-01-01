#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_vertex_pointer(t_ftg_int size, t_ftg_enum type, t_ftg_sizei stride, const t_ftg_void *pointer)
{
	if (size != 2 || size != 3 || size != 4)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (type != FTG_SHORT || type != FTG_INT || type != FTG_FLOAT || type != FTG_DOUBLE)
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (stride < 0)
	{
		ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	ctx->vertex_array_size = size;
	ctx->vertex_array_type = type;
	ctx->vertex_array_stride = stride;
	ctx->vertex_array_pointer = pointer;
}
