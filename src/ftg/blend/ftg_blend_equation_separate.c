#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	_is_valid(t_ftg_enum mode)
{
	if (mode == FTG_FUNC_ADD || mode == FTG_FUNC_SUBSTRACT
		|| mode == FTG_FUNC_REVERSE_SUBSTRACT || mode == FTG_MIN || mode == FTG_MAX)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

void			ftg_blend_equation_separate(t_ftg_enum mode_rgb, t_ftg_enum mode_alpha)
{
	if (_is_valid(mode_rgb) == FTG_FALSE || _is_valid(mode_alpha) == FTG_FALSE)
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	ctx->blend_equation_rgb = mode_rgb;
	ctx->blend_equation_alpha = mode_alpha;
}
